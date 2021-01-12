#pragma once

#include <vector>

class EventCall;

class EventMan
{
public:
    inline EventMan();

    inline void updateEvents();

    template <typename TEVTSYS>
    inline void registerEventSys();            // Registra un tipo de evento

    template <typename TEVTLIS>
    inline TEVTLIS& addEventToListener();         // Añade un event listener

    template <typename TEVENT>
    inline TEVENT& addEvent();                   // Añade un event

private:
    template <typename TEVENT>
    inline size_t getIndexFromEvt();

private:
    std::vector<EventCall*> pEventsSys;
};

#include <ecs/eventSys/EventMan.tpp>