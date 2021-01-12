#pragma once

#include <utils/aliases.h>

#include <cmp/physicsComponent.h>

namespace ECS {
    struct ContextGame {
        virtual ~ContextGame() = default;
        virtual const VectorEntities& GetEntities() const = 0;
        virtual       VectorEntities& GetEntities()       = 0;
        virtual const std::vector<ECS::PhysicsComponent>& GetComponents() const = 0;
        virtual       std::vector<ECS::PhysicsComponent>& GetComponents()       = 0;
    };
}