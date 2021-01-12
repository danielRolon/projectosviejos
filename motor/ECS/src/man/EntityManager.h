#pragma once

/*
sistema de tipos
*/

#include <vector>

#include <cmp/Entity.h>
#include <man/ComponentManager.h>

class EntityManager
{
public:
    inline EntityManager();
    inline ~EntityManager();

    inline void update();

    inline size_t addEntity();
    inline void destroyEntity(size_t idEntity);

    template<typename TMAN> void addManager();

    template<typename TCMP> TCMP& addComponent(size_t idEntity);
    template<typename TCMP> void destroyComponent(size_t idEntity);
    template<typename TCMP> TCMP& getComponent(size_t idEntity);
    template<typename TCMP> TCMP& getComponentFromIdCMP(size_t id);

    template<typename TCMP> size_t getIndexToCmp();


    std::vector<Entity> entities;
    std::vector<ComponentManager*> managers;
    std::unordered_map<int, int> hashTIds;
    
    size_t idCountManagers = 0;
};

#include <man/EntityManager.tpp>