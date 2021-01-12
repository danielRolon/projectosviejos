#pragma once

#include <iostream>
#include <stdlib.h>
#include <windows.h>

class Console
{
public:
    inline static void PrintCharInPos(int x, int y, char c)
    {
        Console::Gotoxy(x, y);
        std::cout << c;
    }

    inline static void Clear()
    {
        system("cls");
    }

    inline static void Gotoxy(int x, int y)
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(consoleHandle, dwPos);
    }

    inline static void SetVisibleMouse(bool visible)
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = visible;
        SetConsoleCursorInfo(consoleHandle, &info);
    }
};