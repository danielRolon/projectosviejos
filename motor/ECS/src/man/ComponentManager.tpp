#pragma once

#include <man/ComponentManager.h>

template <typename TCMP>
TCMP& ComponentManager::addComponent(size_t idEntity)
{
    return *( reinterpret_cast<TCMP*>(components.emplace_back(new TCMP(idEntity)) )    );
}