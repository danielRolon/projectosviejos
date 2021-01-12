#include <console/mouse.h>
#include <winuser.h>
namespace Console
{
    void Mouse::Init()
    {
        cci.dwSize = 25; 
        cci.bVisible = FALSE; 
        SetConsoleCursorInfo(hout, &cci); 
        SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT); 
    }

    void Mouse::Update()
    { 
        switch (InputRecord.EventType)
        {
            case MOUSE_EVENT: // mouse input 
            {
                MouseState = -1;
                MouseButton = -1;
                MousePosition.X = InputRecord.Event.MouseEvent.dwMousePosition.X; 
                MousePosition.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y; 
                MouseButton = (GetAsyncKeyState(MK_RBUTTON) - GetAsyncKeyState(MK_LBUTTON));
                if (GetAsyncKeyState(MK_LBUTTON) || GetAsyncKeyState(MK_RBUTTON)) MouseState  = 1;

                break;
            }
        }
    }

    bool Mouse::IsClick(int button)
    {
        return (MouseState == 1) ? true : false;
    }

    COORD Mouse::GetPosition()
    {
        return MousePosition;
    }
}