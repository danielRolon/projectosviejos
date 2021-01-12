#include <ecs/eventSys/EventMan.h>
#include <ecs/eventSys/EventCall.h>

EventMan::EventMan()
{
    pEventsSys.reserve(32);
}


void EventMan::updateEvents()
{
    for (size_t i = 0; i < pEventsSys.size(); ++i)
    {
        pEventsSys[i]->updateEvents();
    }
}


template <typename TEVTSYS>
void EventMan::registerEventSys()
{
    pEventsSys.emplace_back(new TEVTSYS());
}

template <typename TEVTLIS>
TEVTLIS& EventMan::addEventToListener()
{
    size_t index = getIndexFromEvt<TEVTLIS>();

    auto event = reinterpret_cast<TEVTLIS*>(pEventsSys[index]->addEventToListener());

    return *event;
}

template <typename TEVENT>
TEVENT& EventMan::addEvent()
{
    size_t index = getIndexFromEvt<TEVENT>();

    auto event = reinterpret_cast<TEVENT*>(pEventsSys[index]->addEvent());

    return *event;
}

template <typename TEVENT>
size_t EventMan::getIndexFromEvt()
{
    TEVENT event;

    for (size_t i = 0; i < pEventsSys.size(); ++i)
    {
        if(pEventsSys[i]->getType() ==  event.getType())
        {
            return i;
        }

    }

    perror("Error: Este tipo de evento no esta registrado\n");
}