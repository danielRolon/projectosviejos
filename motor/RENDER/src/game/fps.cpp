#include <game/fps.h>

#include <ctime>
#include <iostream>

unsigned int uiTime  = clock();
unsigned int uiLastTime   = 0u;
unsigned int uiLasTimeSEC = 0u;
unsigned int uiFPSCurrent = 0u;

constexpr unsigned int uiFPSObjetive = 60u;
constexpr unsigned int uiSecInMillis = 1000u;
float                  fDistanceFPS = (float) uiSecInMillis / (float) uiFPSObjetive;

float                  fDeltaDFPS = 0.0f;
float                  fDeltaDSEC = 0.0f;

bool bDebugFPS = false;
bool bDebugDelta = false;
bool bSecondPassed = false;

void setDebug(TypeDebugFPS debugFPS, bool value)
{
    switch (debugFPS)
    {
    case TypeDebugFPS::DELTA:
         bDebugDelta = value;
        break;
    
    case TypeDebugFPS::FPS:
        bDebugFPS = value;
        break;
    default:
        perror("Error: este tipo de debug no existe!!!\n");
        break;
    }
}

void fps(void(*pFunc)(float fDeltaTime))
{
    uiTime = clock();

    fDeltaDFPS = uiTime - uiLastTime;
    fDeltaDSEC = uiTime - uiLasTimeSEC;

    bSecondPassed = false;

    if (fDeltaDSEC >= uiSecInMillis)
    {
        if (bDebugFPS)   std::cout << "FPS: " << uiFPSCurrent << "\n\n";
        if (bDebugDelta) std::cout << "Delta Time: " << fDeltaDFPS/fDistanceFPS << "\n\n\n";

        uiLasTimeSEC = uiTime;
        uiFPSCurrent = 0;
        bSecondPassed = true;
    }

    if (fDeltaDFPS >= fDistanceFPS)
    {
        pFunc(fDeltaDFPS/fDistanceFPS);
        uiLastTime = uiTime;
        ++uiFPSCurrent;
    }
}

bool secondPassed()
{
    return (bSecondPassed);
}