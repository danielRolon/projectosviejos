#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

class KeyboardMan;

#include <sys/entityManager.h>
#include <sys/renderManager.h>
#include <sys/physicsManager.h>
#include <sys/collisionManager.h>

class Game {
public:
    Game();
    ~Game();
    void MainLoop();
private:
    void Update(){}
    void Draw(){}

    bool m_Running = false;
    KeyboardMan* m_KeyMan = nullptr;

    ECS::EntityManager    em {};
    ECS::RenderManager    rm {};
    ECS::PhysicsManager   pm {};
    ECS::CollisionManager cm {};
};

#endif // GAME_H
