#pragma once

#include <string>

class Event;

class EventCall
{
public:
    EventCall() = default;

    virtual void updateEvents() = 0;         // Actualiza los eventos
    virtual Event* addEventToListener() = 0; // Añadiria un event listener
    virtual Event* addEvent() = 0;           // Añadiria un event

    virtual const std::string& getType() const = 0;
};