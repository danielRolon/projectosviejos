#include <windows.h>
#include <math.h>
#include <game/game.h>
#include <game/fps.h>

int main(void)
{
    Renderer2D::Init();

    Renderer2D::LoadTexture("Nave", "res/images/nave.png");

    while (Renderer2D::Events())
    {
        // procces input
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            Renderer2D::Close();
        }

        // procces render
        Renderer2D::Clear();

        fps(game);

        Renderer2D::Refresh();
    }

    Renderer2D::Terminate();

    return 0;
}