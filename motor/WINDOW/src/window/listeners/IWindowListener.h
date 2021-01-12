#pragma once

#include <window/IListener.h>

struct WindowEvent
{
    int windowX = 0, windowY = 0, windowW = 0, windowH = 0;
};

class IWindowListener : public IListener
{
public:
    IWindowListener() {}
    EVENT_TYPE getType() override { return EVENT_TYPE::WINDOW; }
    
    virtual void windowClose(WindowEvent windowEvent) = 0;
    virtual void windowResize(WindowEvent windowEvent) = 0;
    virtual void windowMove(WindowEvent windowEvent) = 0;
};