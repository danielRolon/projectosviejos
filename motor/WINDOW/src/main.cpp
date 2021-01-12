#include <window/Window.h>

int main(int argv, char** args)
{
    bool run = true;
    bool show_another_window = true;

    Window window;
    window.init(800, 450, "Window with Dear ImGui");
    window.initImGui();

    // Main loop
    while (run)
    {
        run = window.updateEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        window.imGuiFrame();

        // Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        window.imGuiRender();

        glfwSwapBuffers(window.getWindow());
    }

    // Cleanup
    window.closeImGui();

    return 0;
}
