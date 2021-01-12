#pragma once

#include <stddef.h>

#define INVALID_COMPONENT_ID -1

namespace ECS
{
    class Component
    {
    public:
        Component(size_t idEntity) : idEntity(idEntity) {}

        inline static size_t nextId { 0 };
        size_t id       { ++nextId };
        size_t idEntity { 0 };
    };
}