#include <GameEngine/WindowSystem/window.h>
#include <iostream>

#define MYWINDOWCLASS "MyWindowClass"

Window* window = nullptr;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_CREATE:
    {
        window->onCreate();
        break;
    }

    case WM_DESTROY:
    {
        window->onDestroy();
        PostQuitMessage(0);
        break;
    }

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return NULL;
}

bool Window::init()
{
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize     = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance     = NULL;
    wc.lpszClassName = MYWINDOWCLASS;
    wc.lpszMenuName  = "";
    wc.style         = NULL;
    wc.lpfnWndProc   = WndProc;
    
    if (!RegisterClassEx(&wc))
    {
        return false;
    }

   if (!window)
        window = this;

    m_hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, MYWINDOWCLASS, "DirectX Application",
                   WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 720, 480, NULL, NULL, NULL, NULL);
    std::cout << "dale xd" << "\n";
    //if (!m_hwnd)
    //    return false;

    ShowWindow(m_hwnd, SW_SHOW);
    UpdateWindow(m_hwnd);

    m_is_run = true;
    
    return true;
}

bool Window::isRun()
{
    return m_is_run;
}

bool Window::broadcast()
{
    MSG msg;

    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    window->onUpdate();

    Sleep(0);

    return true;
}

void Window::onDestroy()
{
    m_is_run = false;
}

bool Window::release()
{
    if (!DestroyWindow(m_hwnd))
        return false;

    return true;
}