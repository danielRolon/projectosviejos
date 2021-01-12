#pragma once

#include <windows.h>

class Input
{
public:
    inline static bool isKeyPressed(char key)
    {
        return (GetAsyncKeyState(key) & 0x8000) ? true : false;
    }
};