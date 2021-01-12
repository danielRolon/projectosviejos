#include <man/EntityManager.h>

#include <utils/global.h>
#include <algorithm>
#include <utils/debug.h>

EntityManager::EntityManager()
{
    entities.reserve(maxEntitiesCount);
    managers.reserve(maxManagersCount);
}

EntityManager::~EntityManager()
{

}

void EntityManager::update()
{
    for (size_t i = 0; i < managers.size(); ++i)
    {
        managers[i]->update(*this);
    }
}

size_t EntityManager::addEntity()
{
    auto& entity = entities.emplace_back();
    return entity.idEntity;
}

void EntityManager::destroyEntity(size_t idEntity)
{
    for (size_t i = 0; i < entities.size(); ++i)
    {
        if (entities[i].idEntity == idEntity)
        {
            entities.erase(entities.begin() + i);
        }
    }

    //Delete al components
}

template<typename TMAN>
void EntityManager::addManager()
{
    //si ya se añado dar error >:)

    //añadirlo :3
    managers.emplace_back(new TMAN(++idCountManagers));

    //guarda su id uwu eres dulce
    hashTIds[managers[hashTIds.size()]->getTypeId()] = hashTIds.size();
}

template<typename TCMP>
TCMP& EntityManager::addComponent(size_t idEntity)
{
    //si no existe su manager dar error

    //obtener el index
    size_t index = getIndexToCmp<TCMP>();

    //añadilo
    auto& component = reinterpret_cast<ComponentManager*>(managers[index])->addComponent<TCMP>(idEntity);

    //retornar el componente
    return component;

}

template<typename TCMP>
void EntityManager::destroyComponent(size_t idEntity)
{
    //si no existe su manager dar error

    //obtener el index
    size_t index = getIndexToCmp<TCMP>();

    //eliminar el componente
    managers[index]->destroyComponent(idEntity);
}

template<typename TCMP>
TCMP& EntityManager::getComponent(size_t idEntity)
{
    //si no existe su manager dar error

    //obtener el index
    size_t index = getIndexToCmp<TCMP>();

    //retorna el componente
    auto component = managers[index]->getComponent(idEntity);

    // si la entidad no lo tiene se manda uno statico
    if (!component)
    {
        static TCMP s_cmp(0);
        return s_cmp;
    }

    return *(reinterpret_cast<TCMP*>(component));
}

template<typename TCMP>
TCMP& EntityManager::getComponentFromIdCMP(size_t id)
{
    //si no existe su manager dar error

    //obtener el index
    size_t index = getIndexToCmp<TCMP>();

    //retorna el componente
    auto component = managers[index]->getComponentFromIdCMP(id);

    // si la entidad no lo tiene se manda uno statico
    if (!component)
    {
        static TCMP s_cmp(0);
        return s_cmp;
    }

    return *(reinterpret_cast<TCMP*>(component));
}

template<typename TCMP>
size_t EntityManager::getIndexToCmp()
{

    for (size_t i = 0; i < managers.size(); ++i)
    {
        if (managers[i]->getTypeId() == TCMP::typeId)
        {
            return i;
        }
    }

    return 444;
}
