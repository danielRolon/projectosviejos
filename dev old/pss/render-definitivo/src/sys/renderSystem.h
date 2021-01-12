#pragma once

#include <sys/renders/renderContext.h>
#include <sys/renders/rago/renderAgo.h>

enum class RenderSelected {
    AGO, CNO
};

namespace ECS {
    struct RenderSystem {
        RenderSystem();
        ~RenderSystem();

        static RenderSystem& p();

        void switchRender();

        IRenderContext* m_Render { nullptr };
    private:

        RenderSelected renderSelected = RenderSelected::AGO;
    };
} // namespace ECS