#pragma once

#include <man/ComponentManager.h>

#include <cmp/PhysicsComponent.h>
#include <cmp/RenderComponent.h>

class PhysicsManager : public ComponentManager
{
public:
    PhysicsManager(size_t idType);
    ~PhysicsManager();

    void update(EntityManager& entityManager) override;
};