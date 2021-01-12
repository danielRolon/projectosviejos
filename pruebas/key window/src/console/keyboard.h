#pragma once

#include <console/console.h>
#include <vector>
namespace Console
{
    class Keyboard
    {
    public:
        static void Update();
        static bool IsKeyPressed(char key);
        static bool IsKeyReleased(char key);

        static bool IsKeyDirectPressed(char key);
    private:
        inline static bool *keys      = new bool[255];
        inline static bool *cache     = new bool[255];
        inline static bool *releaseds = new bool[255];
    };
}