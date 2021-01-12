#include "lib.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>

struct BoxChar {
	const char* text;
	int x;
	int y;
};

namespace Lib {
	namespace Canvas {
		std::vector<BoxChar> boxesBuffer;
		int width = 0;
		int height = 0;
		void init(int width, int height) {
			Lib::Canvas::width = width;
			Lib::Canvas::height = height;
		}
		void draw(const char* text, int x, int y) {
			boxesBuffer.push_back({text, x, y});
		}
		void clear() {
			boxesBuffer.clear();
		}
		void refresh() {

			// DRAW FRAME
			for (unsigned int i = 0; i < boxesBuffer.size(); ++i) {
				Lib::Console::gotoxy(boxesBuffer[i].x, boxesBuffer[i].y);
				printf(boxesBuffer[i].text);
			}
		}
	}

	namespace Console {
		HANDLE hCon;
		COORD dwPos;
		CONSOLE_CURSOR_INFO cci;
		void init(void) {
			hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		}
		void gotoxy(int x, int y) {
			dwPos.X = x;
			dwPos.Y = y;

			SetConsoleCursorPosition(hCon, dwPos);
		}
		void setCursorVisible(bool visible) {
			cci.bVisible = FALSE;
			SetConsoleCursorInfo(hCon, &cci);
		}
		void setCursorSize(int tam) {
			cci.dwSize = tam;
			SetConsoleCursorInfo(hCon, &cci);
		}
		void setColor(int color) {}
	}

	namespace Keyboard {
		std::vector<char> keysChars;
		bool update() {

		}
		bool Down(char keyChar) {
			//if (kbhit()) {
				return (getch() == keyChar) ? true : false;
			//}
		}
	}
}