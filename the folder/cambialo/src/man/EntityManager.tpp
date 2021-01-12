#pragma once

#include <man/EntityManager.h>

#include <std/global.h>

#include <algorithm>

#include <utils/debug.h>

#define MAX_COMPONENTS 100

namespace ECS
{
    EntityManager::EntityManager()
    {
        managers.reserve(MAX_COMPONENTS);
    }

    void EntityManager::update()
    {
        for (auto manager : managers)
        {
            manager->update();
        }
    }

    void
    EntityManager::destroyEntity(size_t idEntity)
    {
        //for (unsigned int i = 0; i < managers.size(); ++i)
        //{
            auto& components = managers[0]->components;
          
            for (size_t j = 0; j < components.size(); ++j)
            {
                //if (components[j]->idEntity == idEntity
                    components.erase(components.begin() + j);
            }
            for (size_t j = 0; j < components.size(); ++j)
            {
                //if (components[j]->idEntity == idEntity
                    components.erase(components.begin() + j);
            }
            LERROR(components.size());
        //}
    }

    template <typename TypeManager> void
    EntityManager::addType()
    {
        if (exist<TypeManager>())
        {
            printf("Error: Este tipo ya esta verificado!!!");
            exit(1);
        }

        managers.emplace_back(reinterpret_cast<ComponentManager*>(new TypeManager()));
        size_t sizeComponent = reinterpret_cast<TypeManager*>(managers[managers.size()-1])->getSizeComponent(); // Obtener el tamaño del tipo casstaticando al tipo de manager
        typesId[sizeComponent] = typesId.size(); // tipo T : 0 | tipo T : 1
    }

    template <typename TypeComponent> void
    EntityManager::addComponent(size_t idEntity)
    {
        if (!exist<TypeComponent>())
        {
            printf("Error: Este tipo no esta verificado!!! Line: %d ", __LINE__);
            exit(1);
        }

		size_t index = getIdType<TypeComponent>();
		managers[index]->addComponent(idEntity);
    }

    template <typename TypeComponent> void
    EntityManager::destroyComponent(size_t idEntity)
    {
        if (!exist<TypeComponent>())
        {
            printf("Error: Este tipo no esta verificado!!! Line: %d ", __LINE__);
            exit(1);
        }

		size_t index = getIdType<TypeComponent>();
		managers[index]->destroyComponent(idEntity);
    }

    template <typename TypeComponent> TypeComponent&
    EntityManager::getComponentByIdEntity(size_t idEntity)
    {
        if (!exist<TypeComponent>())
        {
            printf("Error: Este tipo no esta verificado!!! Line: %d ", __LINE__);
            exit(1);
        }

		size_t index = getIdType<TypeComponent>();
        auto& components = managers[index]->components; // alias

        for (size_t i = 0; i < components.size(); ++i)
        {
            if (components[i]->idEntity == idEntity)
            {
                auto component = reinterpret_cast<TypeComponent*>(components[i]);
                return *component;
            }
        }

        static TypeComponent invalidComponent(INVALID_COMPONENT_ID);

        return invalidComponent;
    }

    template <typename TypeComponent> bool
    EntityManager::exist()
    {
        size_t id = sizeof(TypeComponent);
        return  ( typesId.find(id) == typesId.end() ) ? false : true;
    }
}
