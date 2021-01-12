#pragma once

#include <sys/contextGame.h>

namespace ECS {
    struct CollisionManager {
        CollisionManager();
        ~CollisionManager();

        void Loop(ContextGame&);
    };
} // ECS