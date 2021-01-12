#include <sys/renderManager.h>

#include <iostream>
#include <StdConio.h>

namespace ECS {
    RenderManager::RenderManager() {

    }

    RenderManager::~RenderManager() {

    }

    void RenderManager::Loop(const ContextGame& em) const {

        // Draw Scenary
        for (uint32_t i = 1; i <= 29; i++)
            for (uint32_t j = 0; j <= 1; j++)
                StdConio::DrawCharacterInPos(60 * j, i, '|');

        StdConio::Gotoxy(0, 0);  std::cout << " -----------------------------------------------------------\n";
        StdConio::Gotoxy(0, 30); std::cout << " -----------------------------------------------------------\n";

        // Draw all entities
        const auto& entities = em.GetEntities();
        for (uint32_t i = 0; i < entities.size(); i++) entities[i].Draw();
    }
}
