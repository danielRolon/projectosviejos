#pragma once

#include <ecs/eventSys/eventListener.h>


class KeyEventListener : public EventListener
{
public:
    KeyEventListener() {}

    inline const std::string& getType() const override
    {
        static const std::string keyType = "Keyboard";
        return keyType;
    }
};