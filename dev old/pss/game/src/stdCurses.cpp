#include <stdCurses.h>

int StdCurses::color[8][8];

bool EsColor(const int col);

WINDOW* StdCurses::win = nullptr;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
int StdCurses::init(int x, int y, int w, int h)
{
    // Preinicializacion de N-Curses
    initscr();              // Inicializar N-curses 
    keypad(stdscr, TRUE);   // Mapeo de teclado
    nodelay(stdscr,TRUE);   // Lectura no bloqueante
    notimeout(stdscr,FALSE);
    timeout (0);	           // Para que no se espere en la lectura...
   // nonl();                 // NL no es CR/NL a la salida
    cbreak();               // Disponibilidad inmediata de teclas pulsadas
    noecho();               // Eliminamos el echo al terminal
    curs_set(0);            // Cursor invisible
    leaveok(stdscr,TRUE);   // Cursor siempre en 0,0 tras refresh()
    scrollok(stdscr,FALSE); // No hacer scroll vertical automatico


    if (!has_colors())
    {
        printw("Terminal does not support color");
        getch();
        return -1;
    }

    start_color();

	/*win = newwin(h, w, x, y);
	refresh();

	int hor = 186, ver = 205;
	int esi = 201, esd = 187, eii = 200, eid = 188;
	wborder(win, hor, hor, ver, ver, esi, esd, eii, eid);
	wrefresh(win);*/


    // Inicializamos los pares de colores
    int p = 0;
    int c [8] = { COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW,
                    COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE };
    
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            color[i][j] = p;
            init_pair(p++, c[i], c[j]);
        }
    }

    return 0;
}

void StdCurses::destroy()
{
    if (win) 
    {
        delete win;
        win = nullptr;
    }

	endwin();
}

void StdCurses::refreshWin()
{
    refresh();
}

void StdCurses::setColor(int Atr, int CT, int CF)
{                                  
    attrset(COLOR_PAIR(color[CT][CF]));
    attron(Atr);
}

bool StdCurses::downAsyncKey(unsigned char key)
{
    return (GetAsyncKeyState((unsigned short)key)&0x8000) ? true : false;
}

// Comprueba su el entero representa un color valido...
bool EsColor (const int col)
{
   if (col >= 0 && col < 8) return true;
   return false;
}