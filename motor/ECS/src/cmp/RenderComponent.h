#pragma once

#include <cmp/Component.h>

class RenderComponent : public Component
{
public:
    RenderComponent(size_t idEntity) : Component(idEntity) {}
    char c = 'n';
    unsigned int x = 0, y = 0;
    inline static size_t typeId = 0;
};