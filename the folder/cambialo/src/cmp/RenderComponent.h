#pragma once

#include <cmp/Component.h>

class RenderComponent : public ECS::Component
{
public:
    RenderComponent(size_t idEntity) : ECS::Component(idEntity) {}
    
    unsigned int x { 0 }, y { 0 };
    unsigned int h { 0 };
    char character { 'n' };
};