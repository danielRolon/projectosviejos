#pragma once

enum class EVENT
{
    NONE,
    KEY_PRESSED,
    KEY_RELEASED,
    MOUSE_MOVE,
    MOUSE_SCROLL,
    MOUSE_CLICK,
    WINDOW_RESIZE,
    WINDOW_MOVE,
    WINDOW_CLOSE
};

enum class EVENT_TYPE
{
    NONE,
    KEYBOARD,
    MOUSE,
    WINDOW
};