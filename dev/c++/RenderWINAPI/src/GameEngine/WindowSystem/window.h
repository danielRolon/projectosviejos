#pragma oncee

#include <Windows.h>

class Window
{
public:
    Window() {}
    ~Window() {}

    bool init();
    bool release();
    bool isRun();
    bool broadcast();

    // EVENTS
    virtual void onCreate() = 0;
    virtual void onUpdate() = 0;
    virtual void onDestroy();
protected:
    HWND m_hwnd;
    bool m_is_run;
};