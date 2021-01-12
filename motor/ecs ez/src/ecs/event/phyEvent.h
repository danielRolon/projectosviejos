#pragma once

#include <ecs/eventSys/event.h>

class PhyEvent : public Event
{
public:
    PhyEvent() {}

    inline const std::string& getType() const override
    {
        static const std::string keyType = "Physics";
        return keyType;
    }

    size_t collideEntId;

};

