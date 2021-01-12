#pragma once

#include <memory>

#include <cmp/physicsComponent.h>

class Entity {
public:
    explicit Entity(int, char);
    Entity(const Entity&);
    Entity& operator=(Entity*);
    ~Entity();

    void Update();
    void Draw() const;
public:
    int m_zB { 0 };
    char m_Char { 'n' };
    ECS::PhysicsComponent* m_PhyCmp { nullptr };
};
