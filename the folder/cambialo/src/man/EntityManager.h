#pragma once

#include <cmp/Entity.h>
#include <vector>

#include <unordered_map>

#include <man/ComponentManager.h>

namespace ECS
{
    class EntityManager
    {
    public:
        explicit EntityManager();

        void update();
        inline size_t addEntity() { return ++countEntities; }
               void destroyEntity(size_t idEntity);

        template <typename TypeManager>
        void addType();

        template <typename TypeComponent>
        void addComponent(size_t idEntity);

        template <typename TypeComponent>
        void destroyComponent(size_t idEntity);

        template <typename TypeComponent>
        TypeComponent& getComponentByIdEntity(size_t idEntity);

    //private:
        template <typename TypeComponent>
        bool exist();

        template <typename TypeComponent>
        inline size_t getIdType()
        {
            auto it = typesId.find(sizeof(TypeComponent));
            return it->second;     
        }

        std::vector<ComponentManager*> managers;
        std::unordered_map<size_t, size_t> typesId;

        size_t countEntities { 0 };
    };
}

#include <man/EntityManager.tpp>