#include <keyMan.h>

#include <cinttypes>

int indexOf(const std::vector<unsigned char>& vector, unsigned char otherItem) {
    for (uint32_t i = 0; i < vector.size(); ++i) {
        if (vector[i] == otherItem)
            return i;
    }

    return -1;
}

void KeyMan::keyDown(unsigned char keyCode) {
    if (indexOf(keysDown, keyCode) == -1)
        keysDown.push_back(keyCode);
}

void KeyMan::keyUp(unsigned char keyCode) {
    int index = indexOf(keysDown, keyCode);
    if (index != -1)
        keysDown.erase(keysDown.begin() + index);
}

bool KeyMan::isDown(unsigned char keyCode) {
    return (indexOf(keysDown, keyCode) != -1) ? true : false;
}