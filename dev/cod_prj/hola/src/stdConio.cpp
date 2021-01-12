#include "stdConio.h"

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void StdConio::Clear() {
    system("cls");
}

void StdConio::DrawCharacterInPos(unsigned int x, unsigned int y, unsigned char c) {
    Gotoxy(x, y);
    printf("%c", c);
}

void StdConio::Gotoxy(int x, int y) {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

void StdConio::Hidecursor(bool Hide) {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = !Hide;
   SetConsoleCursorInfo(consoleHandle, &info);
}

