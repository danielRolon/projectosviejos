#ifndef STDCONIO_H
#define STDCONIO_H

#include <windows.h>

class StdConio
{
public:
    static void Clear();
    static void DrawCharacterInPos(unsigned int, unsigned int, unsigned char);

    static void Hidecursor(bool Hide);

    static void Gotoxy(int x, int y);
    private:
};

#endif // STDCONIO_H
