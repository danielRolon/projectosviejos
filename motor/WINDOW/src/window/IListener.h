#pragma once

#include <window/events.h>

class IListener
{
public:
    IListener(){}
    virtual EVENT_TYPE getType() = 0;
};