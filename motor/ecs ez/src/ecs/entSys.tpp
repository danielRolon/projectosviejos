#include <ecs/entSys.h>
#include <ecs/sys.h>
#include <iostream>

EntSys::EntSys(size_t maxSystems)
{
    pSystems.reserve(maxSystems);
}

EntSys::~EntSys()
{

}

void EntSys::update()
{
    // Actualizar eventos
    eventMan.updateEvents();

    // Actualizar componentes
    for (size_t i = 0; i < pSystems.size(); ++i)
    {
        pSystems[i]->update(*this);
    }
}

// Metodos para las entidades
size_t EntSys::addEnt()
{
    return idGenerator();
}

void EntSys::remEnt(size_t id)
{

}

// Metodos para los systemas
template <typename TSYS> void EntSys::addSys()
{
    pSystems.emplace_back(new TSYS());
}

template <typename TCMP> Sys& EntSys::getSysFC()
{
    return *pSystems[TCMP::idSys-1]; // Retornar el systema correto
}

// Metodos para los componetes
template <typename TCMP> TCMP& EntSys::addCmp(size_t idEnt)
{
    Sys& sys = getSysFC<TCMP>();
    return *reinterpret_cast<TCMP*>(sys.addCmp(idEnt));
}

template <typename TCMP> TCMP& EntSys::getCmp(size_t idEnt)
{
    Sys& sys = getSysFC<TCMP>();
    return *reinterpret_cast<TCMP*>(sys.getCmp(idEnt));
}

template <typename TCMP> void EntSys::remCmp(size_t idEnt)
{
    Sys& sys = getSysFC<TCMP>();
    sys.remCmp(idEnt);
}

size_t EntSys::idGenerator()
{
    return ++countEntities;
}