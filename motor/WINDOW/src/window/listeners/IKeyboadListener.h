#pragma once

#include <window/IListener.h>

struct KeyEvent
{
    char keyCode = 0;
};

class IKeyboardListener : public IListener
{
public:
    IKeyboardListener() {}
    EVENT_TYPE getType() override { return EVENT_TYPE::KEYBOARD; }
    
    virtual void keyPressed(KeyEvent keyEvent) = 0;
    virtual void keyReleased(KeyEvent keyEvent) = 0;
};