#pragma once

#include <man/ComponentManager.h>

#include <cmp/RenderComponent.h>

class EntityManager;

class RenderManager : public ComponentManager
{
public:
    RenderManager(size_t typeId);
    ~RenderManager();

    void update(EntityManager& entityManager) override;
};