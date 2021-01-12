#include <man/RenderManager.h>

#include <man/EntityManager.h>

#include <utils/global.h>

#include <utils/console.h>

RenderManager::RenderManager(size_t typeId) : ComponentManager(typeId)
{
    RenderComponent::typeId = typeId;
}

RenderManager::~RenderManager()
{
}

void RenderManager::update(EntityManager& entityManager)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        auto& cmp = *reinterpret_cast<RenderComponent*>(components[i]);
        Console::PrintCharInPos(cmp.x, cmp.y, cmp.c);
    }
}