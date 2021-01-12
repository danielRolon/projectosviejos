#include <ecs/call/phyEventCall.h>
#include <windows.h>
#include <iostream>

#define MAX_COLLIDING_OBJECTS 100

PhyEventCall::PhyEventCall()
{
    events.reserve(MAX_COLLIDING_OBJECTS);
    listeners.reserve(MAX_COLLIDING_OBJECTS);
}

void PhyEventCall::updateEvents()
{
    // Clear Events
    

    // Call Listeners
    for (size_t i = 0; i < listeners.size(); ++i)
    {
        for (size_t j = 0; j < events.size(); ++j)
        {
            listeners[i].behavior(&events[j]);
        }
    }

    //std::cout << keyEvents.size() << "\n";
    events.clear();
}

Event* PhyEventCall::addEventToListener()
{
    return &listeners.emplace_back();
}

Event* PhyEventCall::addEvent()
{
    return &events.emplace_back();
}
