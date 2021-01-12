#pragma once

#include <ecs/cmp.h>

struct PhyCmp : Cmp
{
    PhyCmp(size_t idEnt) : idEnt(idEnt) {}

    float x = 0,
          y = 0,
          vx = 0,
          vy = 0;

    size_t idEnt = 0;
    inline static size_t idSys = 0;
};