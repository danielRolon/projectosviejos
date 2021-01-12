#include <sys/renderSystem.h>

namespace ECS {
    RenderSystem::RenderSystem() {
        m_Render = new RenderAgo2D(640, 360, "Window not changed");
    }

    RenderSystem::~RenderSystem() {
        delete m_Render;
    }

    RenderSystem&  RenderSystem::p() {
        static RenderSystem instance;
        return instance;
    }

    void RenderSystem::switchRender() {
        if (m_Render) delete m_Render;
        switch(renderSelected) {
            case RenderSelected::AGO:
                m_Render = new RenderAgo2D(640, 360, "Window with Allegro");
                renderSelected = RenderSelected::CNO;
                break;
            case RenderSelected::CNO:
                m_Render = new RenderAgo2D(640, 360, "Window with Conio");
                renderSelected = RenderSelected::AGO;
                break;
        }
    }
}