#pragma once

#include <ecs/eventSys/event.h>

class KeyEvent : public Event
{
public:
    KeyEvent() {}

    inline const std::string& getType() const override
    {
        static const std::string keyType = "Keyboard";
        return keyType;
    }

    char keyCode;

};

