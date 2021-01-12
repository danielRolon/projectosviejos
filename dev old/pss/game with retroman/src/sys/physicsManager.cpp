#include <sys/physicsManager.h>

namespace ECS {
    PhysicsManager::PhysicsManager() {}
    
    PhysicsManager::~PhysicsManager() {}

    void PhysicsManager::Loop(ContextGame& gameContext) {
        for (auto& cmp : gameContext.GetComponents()) {
            cmp.x += cmp.vx;
            cmp.y += cmp.vy;
        }
    }
}