#pragma once

#include <sys/contextGame.h>

namespace ECS {
    struct RenderManager {
        RenderManager();
        ~RenderManager();
        void Loop(const ContextGame&) const;
    };
}
