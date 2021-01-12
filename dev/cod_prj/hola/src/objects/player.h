#pragma once

#include "objects/gameObject.h"

class Player : public GameObject {
public:
    Player(unsigned int x, unsigned int y);
    void Update();
    void Draw() const;
};
