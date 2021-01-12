#pragma once

#include <cmp/Component.h>

class PhysicsComponent : public Component
{
public:
    PhysicsComponent(size_t idEntity) : Component(idEntity) {}
    float x = 0, y = 0, vx = 0, vy = 0;
    inline static size_t typeId = 0;
};