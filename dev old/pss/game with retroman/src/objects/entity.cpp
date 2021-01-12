#include "entity.h"

#include <StdConio.h>
#include <keyboardMan.h>
#include <windows.h>

#include <algorithm>

Entity::Entity(int zb, char c)
    : m_zB(zb), m_Char(c) {
    m_PhyCmp = new ECS::PhysicsComponent();
}

Entity::Entity(const Entity& other)
    : Entity(other.m_zB, other.m_Char) {
    m_PhyCmp = other.m_PhyCmp;
}

Entity& Entity::operator=(Entity* other) {
    std::swap(m_PhyCmp, other->m_PhyCmp);
    std::swap(m_Char, other->m_Char);
    std::swap(m_zB, other->m_zB);

    return *this;
}

Entity::~Entity() {

}

void Entity::Update() {
    m_PhyCmp->vx = bool(KeyboardMan::GetLastkeyPressed() == 'd') - bool(KeyboardMan::GetLastkeyPressed() == 'a');
    m_PhyCmp->vy = bool(KeyboardMan::GetLastkeyPressed() == 's') - bool(KeyboardMan::GetLastkeyPressed() == 'w');
}

void Entity::Draw() const {
    StdConio::DrawCharacterInPos(m_PhyCmp->x, m_PhyCmp->y, m_Char);
}
