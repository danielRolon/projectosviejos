#include <game/game.h>

#include <math.h>
#include <windows.h>
#include <game/raycasting.h>

int map[] =
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

int dWidthMap = 10;
int dHeightMap = 10;

float screenWidth = 500;

float tTile     = 32;
float tTileDraw = 10;
float xPlayer = 5 * tTile;
float yPlayer = 5 * tTile;
float aPlayer = degreesToRad(90.0f);

// Player stats
float fSpeed      = 0.025 *tTile, 
      fSpeedSides = 0.025 *tTile, 
      fSpeedRot   = 0.0005*tTile;

const float FOV = 60.0f / 180 * PI;

void drawMap()
{
    for (size_t y = 0; y < dHeightMap; ++y)
    {
        for (size_t x = 0; x < dWidthMap; ++x)
        {
            if (map[x + y * dWidthMap] == 1)
            {
                Renderer2D::SetColor(1.0f, 1.0f, 1.0f);
            }
            else
            {
                Renderer2D::SetColor(0.4f, 0.4f, 0.4f);
            }

            Renderer2D::DrawRect(x * tTileDraw, y * tTileDraw, tTileDraw, tTileDraw);
        }
    }

    Renderer2D::SetColor(0.0f, 1.0f, 0.0f);
    float xPlayerTile = xPlayer / tTile * tTileDraw;
    float yPlayerTile = yPlayer / tTile * tTileDraw;
    Renderer2D::DrawRect(xPlayerTile + tTileDraw/4, yPlayerTile + tTileDraw/4, tTileDraw/2, tTileDraw/2);
}



void game(float fDeltaTime)
{
    // Move Player

    //Angle
    aPlayer += (bool(GetAsyncKeyState('D')) - bool(GetAsyncKeyState('A')) ) * fSpeedRot * fDeltaTime;

    float xOldPlayer = xPlayer;
    float yOldPlayer = yPlayer;

    //Forward
    xPlayer += cos(aPlayer) * bool(GetAsyncKeyState('W')) * fSpeed * fDeltaTime;
    yPlayer += sin(aPlayer) * bool(GetAsyncKeyState('W')) * fSpeed * fDeltaTime;

    //Back
    xPlayer -= cos(aPlayer) * bool(GetAsyncKeyState('S')) * fSpeed * fDeltaTime;
    yPlayer -= sin(aPlayer) * bool(GetAsyncKeyState('S')) * fSpeed * fDeltaTime;

    // Collision
    int xMap = floor(xPlayer/tTile);
    int yMap = floor(yPlayer/tTile);
    int xOldMap = floor(xOldPlayer/tTile);
    int yOldMap = floor(yOldPlayer/tTile);

    
    if (map[xMap + yOldMap * dWidthMap] == 1) xPlayer = xOldPlayer; // Collision horizontal
    if (map[xOldMap + yMap * dWidthMap] == 1) yPlayer = yOldPlayer; // Collision vertical

    xOldPlayer = xPlayer;
    yOldPlayer = yPlayer;

    //Side left
    xPlayer += cos(aPlayer - PI/2) * bool(GetAsyncKeyState('J')) * fSpeedSides * fDeltaTime;
    yPlayer += sin(aPlayer - PI/2) * bool(GetAsyncKeyState('J')) * fSpeedSides * fDeltaTime;

    //Side right
    xPlayer += cos(aPlayer + PI/2) * bool(GetAsyncKeyState('L')) * fSpeedSides * fDeltaTime;
    yPlayer += sin(aPlayer + PI/2) * bool(GetAsyncKeyState('L')) * fSpeedSides * fDeltaTime;

    // Collision
    xMap = floor(xPlayer/tTile);
    yMap = floor(yPlayer/tTile);
    xOldMap = floor(xOldPlayer/tTile);
    yOldMap = floor(yOldPlayer/tTile);

    
    if (map[xMap + yOldMap * dWidthMap] == 1) xPlayer = xOldPlayer; // Collision horizontal
    if (map[xOldMap + yMap * dWidthMap] == 1) yPlayer = yOldPlayer; // Collision vertical

    rayCasting(map, SCREEN_WIDTH, SCREEN_HEIGHT, FOV, aPlayer, xPlayer, yPlayer, dWidthMap, dHeightMap, tTile, tTileDraw);

    //if (GetKeyState('M'))
    drawMap();
}