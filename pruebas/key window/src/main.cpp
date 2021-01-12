#include <console/render.h>
#include <console/keyboard.h>

constexpr int FPS = 1000/30;

int main()
{
	Image16* image16 = Console::Render::LoadPPM("res/mario00.ppm");

	Console::Render::Init();

	float x = 0.0f, y = 0.0f;

	while(!GetAsyncKeyState(VK_ESCAPE))
	{

		Console::Keyboard::Update();

		x += Console::Keyboard::IsKeyDirectPressed('D') - Console::Keyboard::IsKeyDirectPressed('A');
		y += Console::Keyboard::IsKeyDirectPressed('S') - Console::Keyboard::IsKeyDirectPressed('W');

		Console::Render::Clear();
		Console::Render::SetColor(C_LIGHT_GREEN);
		//Console::Render::DrawImage15T(image16, (int)x, (int)y);
		Console::Render::FillRect((int)x,(int)y,10,10);
		Console::Render::Flush();

		Sleep(FPS);
	}

	Console::Render::SetColor(C_LIGHT_GRAY);

	Console::Render::Free();
}