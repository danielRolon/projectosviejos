#include <man/PhysicsManager.h>

#include <utils/global.h>
#include <utils/console.h>
#include <utils/debug.h>


#include <man/EntityManager.h>

PhysicsManager::PhysicsManager(size_t typeId) : ComponentManager(typeId)
{
    PhysicsComponent::typeId = typeId;
}

PhysicsManager::~PhysicsManager()
{
}


void PhysicsManager::update(EntityManager& entityManager)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        auto& cmp = *reinterpret_cast<PhysicsComponent*>(components[i]);
        //auto& renCmp = entityManager.getComponent<RenderComponent>(cmp.idEntity);

        for (size_t j = 0; j < components.size(); ++j)
        {
            if (j == i) continue;

            auto& c_cmp = *reinterpret_cast<PhysicsComponent*>(components[j]);

            if (cmp.x + cmp.vx == c_cmp.x && cmp.y == c_cmp.y) cmp.vx = 0;
            if (cmp.y + cmp.vy == c_cmp.y && cmp.x == c_cmp.x) cmp.vy = 0;
        }
    }

    for (size_t i = 0; i < components.size(); ++i)
    {
        auto& cmp = *reinterpret_cast<PhysicsComponent*>(components[i]);
        auto& renCmp = entityManager.getComponent<RenderComponent>(cmp.idEntity);  

        cmp.x += cmp.vx;
        cmp.y += cmp.vy;

        if (renCmp.idEntity == 0) return;

        renCmp.x = cmp.x;
        renCmp.y = cmp.y;
    }
}