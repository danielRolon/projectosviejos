#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

class KeyboardMan;

#include "objects/gameObject.h"

class Game {
public:
    Game();
    ~Game();
    void MainLoop();
private:
    void Update();
    void Draw();

    bool m_Running = false;
    KeyboardMan* m_KeyMan = nullptr;

    std::vector<std::unique_ptr<GameObject>> m_Objects {};
};

#endif // GAME_H
