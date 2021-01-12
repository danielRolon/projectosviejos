#pragma once

#include <windows.h>

#include <stdint.h>

class Input
{
public:
    inline static uint8_t isKeyPressed(char key)
    {
        return (GetAsyncKeyState(key) & 0x8000) ? true : false;
    }
};