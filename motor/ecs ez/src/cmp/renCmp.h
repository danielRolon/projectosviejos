#pragma once

#include <ecs/cmp.h>

struct RenCmp : Cmp
{
    RenCmp(size_t idEnt) : idEnt(idEnt) {}

    float x = 0, y = 0, lx = 0, ly = 0;
    unsigned char representation = '-';

    size_t idEnt = 0;
    inline static size_t idSys = 0;
};