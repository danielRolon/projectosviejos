#pragma once

#include <ecs/eventSys/EventCall.h>
#include <vector>
#include <ecs/event/keyEvent.h>
#include <ecs/event/keyEventListener.h>

class KeyEvtCall : public EventCall
{
public:
    KeyEvtCall();
    
    void updateEvents()       override; // Actualiza los eventos
    Event* addEventToListener() override; // Añadiria un event listener
    Event* addEvent()           override; // Añadiria un event

    inline const std::string& getType() const override
    {
        static const std::string keyType = "Keyboard";
        return keyType;
    }

private:
    std::vector<KeyEvent> keyEvents;
    std::vector<KeyEventListener> keyListeners;
};