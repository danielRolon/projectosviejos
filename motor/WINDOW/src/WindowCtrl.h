#pragma once

#include <iostream>
#include <window/listeners/IWindowListener.h>

class WindowCtrl : public IWindowListener
{
public:
    WindowCtrl() {}
    EVENT_TYPE getType() override { return EVENT_TYPE::WINDOW; }
    
    void windowClose(WindowEvent windowEvent) override {
        std::cout << "Window Closed ;(" << "\n";
    }
    void windowResize(WindowEvent windowEvent) override {}
    void windowMove(WindowEvent windowEvent) override {}
};