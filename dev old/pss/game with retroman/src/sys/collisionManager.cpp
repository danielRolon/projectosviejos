#include <sys/collisionManager.h>

namespace ECS {
    CollisionManager::CollisionManager() {}

    CollisionManager::~CollisionManager() {}

    void CollisionManager::Loop(ContextGame& contextGame) {
        for (auto& e : contextGame.GetEntities()) {
            if (e.m_PhyCmp) {
                if (e.m_PhyCmp->x + e.m_PhyCmp->vx < 1)    e.m_PhyCmp->x = 1;
                if (e.m_PhyCmp->y + e.m_PhyCmp->vy < 1)    e.m_PhyCmp->y = 1;
                if (e.m_PhyCmp->x + e.m_PhyCmp->vx > 60-1) e.m_PhyCmp->x = 60-1;
                if (e.m_PhyCmp->y + e.m_PhyCmp->vy > 30-1) e.m_PhyCmp->y = 30-1;
            }
        }
    }

} // ECS
