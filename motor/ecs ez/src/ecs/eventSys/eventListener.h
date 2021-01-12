#pragma once

#include <ecs/eventSys/event.h>
#include <functional>

class EventListener : public Event
{
public:
    EventListener() {}
    
    std::function<void(Event*)> behavior;

    virtual const std::string& getType() const = 0;
};