#include <man/RenderManager.h>
#include <std/console.h>

#include <algorithm>

#include <utils/debug.h>

RenderManager::RenderManager()
{
    components.reserve(MAX_ENTITIES);
}

void
RenderManager::update()
{
    for (auto& cmp : components)
    {
        auto renCmp = static_cast<RenderComponent*>(cmp);
        Console::pushCharacterIn(renCmp->x, renCmp->y, renCmp->character);
    }
}

void
RenderManager::addComponent(size_t idEntity)
{
    components.emplace_back(new RenderComponent(idEntity));
}

void
RenderManager::destroyComponent(size_t idEntity)
{
    int index = -1;
    for (size_t i = 0; i < components.size(); ++i)
    {
        if (components[i]->idEntity == idEntity)
            index = i;
    }

    if (index != -1)
    {
        components.erase(components.begin() + index);
    }
    else
    {
        LERROR("El id de identidad no existe");
    }
}

std::vector<ECS::Component*>&
RenderManager::getComponents()
{
    return components;
}

RenderComponent&
RenderManager::getComponentByIdEntity(size_t idEntity)
{
    /*auto it  =  std::find_if(components.begin(), components.end(),
                [&](const RenderComponent& renCmp)
                {
                    return (renCmp.idEntity == idEntity) ? true : false;
                });

    if (it != components.end())
        return *it;

    static RenderComponent invalidComponent(INVALID_COMPONENT_ID);

    return invalidComponent;*/
}
