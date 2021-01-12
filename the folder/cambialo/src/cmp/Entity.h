#pragma once

#include <stddef.h>

namespace ECS
{
    class Entity
    {
    public:
        inline static size_t nextId { 0 };
        size_t idEntity { ++nextId };
    };
}