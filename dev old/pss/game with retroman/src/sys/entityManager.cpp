#include "entityManager.h"

#include <iostream>

namespace ECS {

    EntityManager::EntityManager(int MaxObjectsCount) {
        m_Entities.reserve(MaxObjectsCount);
    }

    void EntityManager::Loop() {
        // Update all entities
        for (uint32_t i = 0; i < m_Entities.size(); i++) m_Entities[i].Update();
    }

    void EntityManager::AddObject(int x, int y, int zb, char c) {
        auto& e = m_Entities.emplace_back(zb, c);

        e.m_PhyCmp = &m_CmpStorage.AddComponent();
        e.m_PhyCmp->x = 5;
        e.m_PhyCmp->y = 5;
    }

} // ECS
