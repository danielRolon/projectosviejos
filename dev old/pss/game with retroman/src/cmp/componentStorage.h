#pragma once

#include <vector>
#include <cmp/physicsComponent.h>

namespace ECS {
    struct ComponentStorage {
        ComponentStorage() = delete;
        explicit ComponentStorage(std::size_t MaxComponents);

        ComponentStorage(const ComponentStorage&) = delete;
        ComponentStorage(ComponentStorage&&) = delete;
        ComponentStorage& operator=(const ComponentStorage&) = delete;
        ComponentStorage& operator=(ComponentStorage&&) = delete;

        PhysicsComponent& AddComponent();

        const std::vector<ECS::PhysicsComponent>& GetComponents() const { return m_Components; }
              std::vector<ECS::PhysicsComponent>& GetComponents()       { return m_Components; }

    //private:
        std::vector<PhysicsComponent> m_Components {};
    };
} // namespace ECS