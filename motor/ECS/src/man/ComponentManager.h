#pragma once

#include <utils/aliases.h>

#include <utils/global.h>

class EntityManager;

class ComponentManager
{
public:
    ComponentManager(size_t typeId) { 
        components.reserve(maxEntitiesCount);
        this->typeId = typeId;
    }
    virtual ~ComponentManager() {}

    virtual void update(EntityManager& entityManager) = 0;
    template <typename TCMP> TCMP& addComponent(size_t idEntity);

    inline bool destroyComponent(size_t idEntity)
    {
        for (size_t i = 0; i < components.size(); ++i)
        {
            if (components[i]->idEntity == idEntity)
            {
                components.erase(components.begin() + i);
                return true;
            }
        }
        return false;
    }

    inline Component* getComponent(size_t idEntity)
    {
        for (size_t i = 0; i < components.size(); ++i)
        {
            if (components[i]->idEntity == idEntity)
            {
                return components[i];
            }
        }

        return nullptr;
    }

    inline Component* getComponentFromIdCMP(size_t id)
    {
        for (size_t i = 0; i < components.size(); ++i)
        {
            if (components[i]->id == id)
            {
                return components[i];
            }
        }

        return nullptr;
    }

    size_t getTypeId() { return typeId; };

protected:
    VecCmp components;
    size_t typeId = 0;
};

#include <man/ComponentManager.tpp>