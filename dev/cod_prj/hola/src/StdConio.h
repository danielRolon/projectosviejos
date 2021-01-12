#ifndef STDCONIO_H
#define STDCONIO_H

#include <windows.h>

class StdConio
{
public:
    static void Clear();
    static void DrawCharacterInPos(unsigned int, unsigned int, unsigned char);

    static void Hidecursor(bool Hide);
private:
    static void Gotoxy(int x, int y);
};

#endif // STDCONIO_H
