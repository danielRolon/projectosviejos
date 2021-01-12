#include <chrono>

#include <Windows.h>
#include <math.h>
#include <string>

#include <console.h>

#define PI 3.14159

int nScreenWidth = 120;
int nScreenHeight = 40;

float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;

int nMapWidth = 16;
int nMapHeight = 16;

float fFOV = PI / 4.0f;
float fDepth = 12.0f;

int main() {
	// Create Screen buffer
	char *screen = new char[nScreenWidth * nScreenHeight];
	//HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//SetConsoleActiveScreenBuffer(hConsole);
	//DWORD dwBytesWritten = 0;

	std::wstring map;

	map += L"################";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#...########...#";
	map += L"#...########...#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#...############";
	map += L"#...############";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"################";

	auto tp1 = std::chrono::system_clock::now();
	auto tp2 = std::chrono::system_clock::now();

	float fPlayerVX = 0;
	float fPlayerVY = 0;

	bool running = true;

	// Game Loop
	while (running) {
		clear();
		
		tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();

		// Controls
		// Handle CCW Rotation
		int nPlayerRot = bool(GetAsyncKeyState((unsigned short)'D') & 0x8000) - bool(GetAsyncKeyState((unsigned short)'A') & 0x8000);
		int nPlayerMov = bool(GetAsyncKeyState((unsigned short)'W') & 0x8000) - bool(GetAsyncKeyState((unsigned short)'S') & 0x8000);
  
		// Player Angle or Movement Right/Left
		if (GetAsyncKeyState((unsigned short)VK_SHIFT) & 0x8000) {
			fPlayerX += (sinf(fPlayerA+PI/2) * 2.0f * fElapsedTime) * nPlayerRot;
			fPlayerY += (cosf(fPlayerA+PI/2) * 2.0f * fElapsedTime) * nPlayerRot;		
			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#')  {
				fPlayerX -= (sinf(fPlayerA+PI/2) * 2.0f * fElapsedTime) * nPlayerRot;
				fPlayerY -= (cosf(fPlayerA+PI/2) * 2.0f * fElapsedTime) * nPlayerRot;
			}
		} else { 
			fPlayerA -= ((1.4f) * fElapsedTime) * -nPlayerRot;
		}



		// Player Position
		fPlayerX += (sinf(fPlayerA) * 6.0f * fElapsedTime) * nPlayerMov;
		fPlayerY += (cosf(fPlayerA) * 6.0f * fElapsedTime) * nPlayerMov;

		if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#')  {
			fPlayerX -= (sinf(fPlayerA) * 6.0f * fElapsedTime) * nPlayerMov;
			fPlayerY -= (cosf(fPlayerA) * 6.0f * fElapsedTime) * nPlayerMov;
		}


		if (GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000)
			running = false;

		for (int x = 0; x < nScreenWidth; ++x) {
			// For each column, calculate the projected ray angle into world space
			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

			float fDistanceToWall = 0;
			bool bHitWall = false;

			float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall && fDistanceToWall < fDepth) {
				fDistanceToWall += 0.1f;

				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				// Test if ray out of bound
				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
					bHitWall = true;            // Just set distance to maximun depth
					fDistanceToWall = fDepth;
				} else {
					// Ray is inbounds so test see if the tay cel is wall block
					if (map[nTestY * nMapWidth + nTestX] == '#') {
						bHitWall = true;
					}
				}
			}

			// Calculate distance to ceiling and floor
			float fDistanceFix =  fDistanceToWall; //* cosf(fPlayerA - fRayAngle); // Fix distance
			int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / (float)fDistanceFix;
			int nFloor = nScreenHeight - nCeiling;

			// Algorithm to change shading
			short nShade = ' ';
			short* arrShades = new short[4];
			std::size_t szShades = 3;
			arrShades[0] = 176;
			arrShades[1] = 177;
			arrShades[2] = 178;
			arrShades[3] = 219;

			for (int i = szShades; i >= 0; --i) {
				if (fDistanceFix <= fDepth / (i+1)) {
					nShade = arrShades[i];
					break;
				}
			}

			// Draw column
			for (int y = 0; y < nScreenHeight; ++y) {
				if ( y < nCeiling)
					screen[y * nScreenWidth + x] = ' ';
				else if (y > nCeiling && y <= nFloor)
					screen[y * nScreenWidth + x] = nShade;
				else {
					// Algorithm to change floor shading 
					float b = 1.0f - (((float)y - nScreenHeight / 2.0f) / ((float)nScreenHeight / 2.0f));

					short nShadeF = ' ';
					short* arrShadesF = new short[4];
					std::size_t szShadesF = 3;
					arrShadesF[0] = '#';
					arrShadesF[1] = 'x';
					arrShadesF[2] = '-';
					arrShadesF[3] = '.';

					for (int i = 0; i < szShadesF; ++i) {
						if (b < 0.25 * (i+1)) {
							nShadeF = arrShadesF[i];
							break;
						}
					}
					screen[y * nScreenWidth + x] = nShadeF;
				}

				if (x == nScreenWidth-1) screen[x + y * nScreenWidth] = '\n'; 
			}
		}

		// Display Stats
		//swprintf(screen, L"X=%3.2f, Y=%3.2f, A=%3.2f FPS=%3.2f ", fPlayerX, fPlayerY, fPlayerA, 1.0f/fElapsedTime);
		

		screen[nScreenWidth + nScreenHeight - 1] = '\0';
		//screen[0] = '31m';

		move(0, 0);
		printf(screen);
		//WriteConsoleOutputCharacterA(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	}

	return 0;
}