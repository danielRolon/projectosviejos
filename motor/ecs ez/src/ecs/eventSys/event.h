#pragma once

#include <string>

class Event
{
public:
    Event() {}
    virtual const std::string& getType() const = 0;
};