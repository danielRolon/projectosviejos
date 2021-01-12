#pragma once

#include <cmp/Component.h>
#include <vector>

namespace ECS
{
class ComponentManager
{
public:
    explicit ComponentManager() = default;

    virtual void update() = 0;

    virtual void addComponent(size_t idEntity) = 0;
    virtual void destroyComponent(size_t idEntity) = 0;

    virtual std::vector<Component*>& getComponents() = 0;

    virtual Component& getComponentByIdEntity(size_t idEntity) = 0;

    virtual size_t getSizeComponent() const { return sizeof(Component); }

    std::vector<Component*> components;
};
}