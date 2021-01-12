#pragma once

#include <sys/contextGame.h>

namespace ECS {

    class PhysicsManager {
    public:
        PhysicsManager();
        ~PhysicsManager();

        void Loop(ContextGame&);
    };
    
    
} // ECS