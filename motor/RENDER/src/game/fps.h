#pragma once

// Debugs
enum class TypeDebugFPS
{
    DELTA,
    FPS
};

void setDebug(TypeDebugFPS debugFPS, bool value);
void fps(void(*pFunc)(float fDeltaTime));
bool secondPassed();