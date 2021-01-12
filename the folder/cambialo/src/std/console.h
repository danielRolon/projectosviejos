#pragma once

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include <std/global.h>

class Console
{
public:
    inline static void clearConsole()
    {
        system("clear");
    }

    inline static void pushCharacterIn(stdint x, stdint y, char character)
    {
        Console::moveCursor(x, y);
        printf("%c", character);
    }

    inline static void moveCursor(stdint x, stdint y)
    {
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon, dwPos);
    }

    inline static void showCursor(bool show)
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = show;
        SetConsoleCursorInfo(consoleHandle, &info);
    }
};