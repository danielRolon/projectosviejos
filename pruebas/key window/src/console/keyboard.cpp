#include <console/keyboard.h>

namespace Console
{
    void Keyboard::Update()
    {
        for (int i = (int)'A'; i <= (int)'Z'; ++i)
        {
            keys[i] = false;
            releaseds[i] = false;

            if (GetAsyncKeyState(i))
            {
                if (!cache[i])
                {
                    keys[i]  = true;
                    cache[i] = true;
                }
                
            }
            else
            {
                if (cache[i])
                {
                    releaseds[i] = true;
                    cache[i] = false;
                }
                
            }
        }
    }

    bool Keyboard::IsKeyPressed(char key)
    {
        return keys[(int)key];
    }

    bool Keyboard::IsKeyReleased(char key)
    {
        return releaseds[(int)key];
    }

    bool Keyboard::IsKeyDirectPressed(char key)
    {
        return bool(GetAsyncKeyState(key));
    }
}