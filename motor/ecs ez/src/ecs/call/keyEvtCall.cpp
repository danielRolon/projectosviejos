#include <ecs/call/keyEvtCall.h>
#include <windows.h>
#include <iostream>

#define MAX_KEYS_PRESSED 10

KeyEvtCall::KeyEvtCall()
{
    keyEvents.reserve(MAX_KEYS_PRESSED);
    keyListeners.reserve(MAX_KEYS_PRESSED);
}

void KeyEvtCall::updateEvents()
{
    // Clear Events
    keyEvents.clear();

    // Add events
    for (size_t i = 'A'; i < 'Z'; ++i)
    {
        if (GetAsyncKeyState(i))
        {
            auto pKeyEvent = reinterpret_cast<KeyEvent*>(addEvent());
            pKeyEvent->keyCode = i;
        }
    }

    // Call Listeners
    for (size_t i = 0; i < keyListeners.size(); ++i)
    {
        for (size_t j = 0; j < keyEvents.size(); ++j)
        {
            keyListeners[i].behavior(&keyEvents[j]);
        }
    }

    //std::cout << keyEvents.size() << "\n";
}

Event* KeyEvtCall::addEventToListener()
{
    return &keyListeners.emplace_back();
}

Event* KeyEvtCall::addEvent()
{
    return &keyEvents.emplace_back();
}
