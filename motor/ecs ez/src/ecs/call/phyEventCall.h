#pragma once

#include <ecs/eventSys/EventCall.h>
#include <vector>
#include <ecs/event/phyEvent.h>
#include <ecs/event/phyEventListener.h>

class PhyEventCall : public EventCall
{
public:
    PhyEventCall();
    
    void updateEvents()       override; // Actualiza los eventos
    Event* addEventToListener() override; // Añadiria un event listener
    Event* addEvent()           override; // Añadiria un event

    inline const std::string& getType() const override
    {
        static const std::string Type = "Physics";
        return Type;
    }

private:
    std::vector<PhyEvent> events;
    std::vector<PhyEventListener> listeners;
};