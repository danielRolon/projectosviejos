#pragma once

#include <console/console.h>

#define CONSOLE_MB_LEFT     -1
#define CONSOLE_MB_RIGHT     1
#define CONSOLE_MB_PRESSED   0
#define CONSOLE_MB_RELEASED  1

namespace Console
{
    class Mouse
    {
    public:
        static void Init();
        static void Update();
        static bool IsClick(int button);
        static COORD GetPosition();
    private:
        inline static COORD MousePosition{ 0, 0 };
        inline static int   MouseState = -1, MouseButton = -1;
    };
}