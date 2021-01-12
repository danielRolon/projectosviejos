#pragma once

#include <vector>
#include <window/events.h>
#include <window/IListener.h>
#include <IMGUI/imgui.h>
#include <IMGUI/imgui_impl_glfw.h>
#include <IMGUI/imgui_impl_opengl3.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

class Window
{
public:
    Window() = default;
    ~Window();

    int init(int width, int height, const char* title);
    void initImGui();
    void closeImGui();

    void addListener(IListener* listener);

    bool updateEvents();
    void imGuiFrame();
    void imGuiRender();

    void setTitle(const char* title);

    inline int getWidth() { return width; }
    inline int getHeight() { return height; }
    inline GLFWwindow* getWindow() { return window; }

private:
    // window
    bool run = false;
    int width = 0, height = 0;
    GLFWwindow* window;
    // events
    struct DATA
    {
        char keyCode = 'n';
        int mouseX = 0, mouseY = 0;
        int windowX = 0, windowY = 0, windowW = 0, windowH = 0;
        int mouseScroll = 0, mouseScrollVel;
    };
    DATA* data = new DATA();
    EVENT event = EVENT::NONE;
    std::vector<IListener*> listeners;
public:
    inline static DATA* s_data = nullptr;
    inline static EVENT s_event = EVENT::NONE;
};