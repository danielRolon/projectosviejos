#include <window/Window.h>
#include <window/listeners/IKeyboadListener.h>
#include <window/listeners/IWindowListener.h>
#include <iostream>

// callbacks
void callbackPos(GLFWwindow* window, int xpos, int ypos)
{
    Window::s_event = EVENT::WINDOW_MOVE;
    Window::s_data->windowX = xpos;
    Window::s_data->windowY = ypos;

    //std::cout << "The new position of window is: " << "xpos: " << xpos << " and ypos: " << ypos << "\n";
}

void callbackSize(GLFWwindow* window, int width, int height)
{
    Window::s_event = EVENT::WINDOW_RESIZE;
    Window::s_data->windowW = width;
    Window::s_data->windowH = height;

    //std::cout << "The new size of window is: " << "width: " << width << " and height: " << height << "\n";
}

void callbackClose(GLFWwindow* window)
{
    Window::s_event = EVENT::WINDOW_CLOSE;

    //std::cout << "The window is closing" << "\n";
}

void callbackKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Window::s_event = EVENT::KEY_PRESSED;
    Window::s_data->keyCode = key;

    std::cout << "a key is pressed. Key code is: " << key << "                          other dates: " << scancode << ", " << action << ", " << mods << "\n";
}

int Window::init(int width, int height, const char* title)
{
    this->width = width;
    this->height = height;
    this->run = true;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    glfwSwapInterval(1); // Enable vsync

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initialize OpenGL loader
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

    /* Initialize the static members */
    s_data = data;
    s_event = event;

    /* Set Callbacks of window */
    glfwSetWindowPosCallback(window, callbackPos);
    glfwSetWindowSizeCallback(window, callbackSize);
    glfwSetWindowCloseCallback(window, callbackClose);
    glfwSetKeyCallback(window, callbackKey);
}

void Window::initImGui()
{
    const char* glsl_version = "#version 130";

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
 
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Window::imGuiFrame()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Window::imGuiRender()
{
    // Rendering
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());  
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::closeImGui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Window::addListener(IListener* listener)
{
    listeners.emplace_back(listener);
}

bool Window::updateEvents()
{
    /* Poll for and process events */
    glfwPollEvents();

    /* Call Listeners */
    for (size_t i = 0; i < listeners.size(); ++i)
    {
        auto listener = listeners[i];
        EVENT_TYPE type = listener->getType();

        switch(type)
        {
            case EVENT_TYPE::KEYBOARD:
            {
                auto keyboardL = reinterpret_cast<IKeyboardListener*>(listener);
                KeyEvent KeyEvent{data->keyCode};

                switch(event)
                {
                    case EVENT::KEY_PRESSED:
                        keyboardL->keyPressed(KeyEvent);
                    break;

                    case EVENT::KEY_RELEASED:
                        keyboardL->keyReleased(KeyEvent);
                    break;
                }

                break;
            }

            case EVENT_TYPE::WINDOW:
            {
                auto windowL = reinterpret_cast<IWindowListener*>(listener);
                WindowEvent windowEvent{data->windowX, data->windowY, data->windowH, data->windowH};

                switch (event)
                {
                    case EVENT::WINDOW_CLOSE:
                        windowL->windowClose(windowEvent);
                        run = false;
                    break;

                    case EVENT::WINDOW_MOVE:
                        windowL->windowMove(windowEvent);
                    break;

                    case EVENT::WINDOW_RESIZE:
                        windowL->windowResize(windowEvent);
                    break;
                }
                
                break;
            }
            
        }
    }

    if (glfwWindowShouldClose(window))  run = false;

    event = EVENT::NONE;

    return run;
}

void Window::setTitle(const char* title)
{
    glfwSetWindowTitle(window, title);
}