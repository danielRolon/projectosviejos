#pragma once

#include <ecs/eventSys/eventListener.h>


class PhyEventListener : public EventListener
{
public:
    PhyEventListener() {}

    inline const std::string& getType() const override
    {
        static const std::string keyType = "Physics";
        return keyType;
    }
};