#pragma once

#include <curses.h>
#include <Windows.h>

class StdCurses
{
    public:
        static int init(int, int, int, int);
        static void destroy();

        static void refreshWin();

        static void setColor(int Atr, int CT, int CF);

        static bool downAsyncKey(unsigned char);

        static WINDOW* win;

        static int color[8][8];

};