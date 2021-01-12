#pragma once

#define MAX_ENTITIES 1024

#include <vector>
#include <ecs/cmp.h>

class EntSys;

struct Sys
{
    size_t getID() { return idSys; }

    //Actualiza los componentes
    virtual void update(EntSys& entSys) = 0;

    // Añadir, obtener y eliminar componntes
    virtual Cmp* addCmp(size_t idEnt) = 0;
    virtual Cmp* getCmp(size_t idEnt) = 0;
    virtual void remCmp(size_t idEnt) = 0;

protected:
    inline static size_t countSys = 0;
    const size_t idSys = ++countSys;
};