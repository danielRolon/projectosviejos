#pragma once

#include <ecs/cmp.h>
#include <functional>

class EntSys;

struct ScrCmp : Cmp
{
    ScrCmp(size_t idEnt) : idEnt(idEnt) {}
    
    std::function<void(EntSys&, size_t)> behavior;

    size_t idEnt = 0;
    inline static size_t idSys = 0;
};