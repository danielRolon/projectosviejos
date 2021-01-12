#pragma once

#include <stdlib.h>

struct Component
{
    Component(size_t idEntity) : idEntity(idEntity) {}
    size_t id {++idCount};
    size_t idEntity { 0 };
private:
    inline static size_t idCount { 0 };
};