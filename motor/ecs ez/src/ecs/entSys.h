#pragma once

#include <vector>
#include <ecs/eventSys/eventMan.h>

class Sys;

class EntSys
{
public:
    inline EntSys(size_t maxSystems);
    inline~EntSys();

    inline void update();

    // Metodos para las entidades
    inline size_t addEnt();
    inline void   remEnt(size_t id);

    // Metodos para los systemas
    template <typename TSYS> inline void addSys();

    // Metodos para los componetes
    template <typename TCMP> 
    inline TCMP& addCmp(size_t idEnt);
    template <typename TCMP> 
    inline TCMP& getCmp(size_t idEnt);

    // Manejador de events
    EventMan eventMan;

private:
    inline size_t idGenerator();
    template <typename TCMP> 
    inline Sys& getSysFC();
    template <typename TCMP> 
    inline void remCmp(size_t idEnt);
private:
    std::vector<Sys*> pSystems;
    
    inline static size_t countEntities = 0;
};

#include <ecs/entSys.tpp>