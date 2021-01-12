#pragma once

#include <vector>

class KeyMan {
public:
    KeyMan() {}
    ~KeyMan() {}

    static KeyMan& P() {
        static KeyMan instance;
        return instance;
    }

    void keyDown(unsigned char keyCode);

    void keyUp(unsigned char keyCode);

    bool isDown(unsigned char keyCode);

private:
    std::vector<unsigned char> keysDown;
};