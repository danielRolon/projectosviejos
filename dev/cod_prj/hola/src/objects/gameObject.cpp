#include "objects/gameObject.h"

#include "StdConio.h"

GameObject::GameObject(int x, int y, int zb, bool solid, char c)
    : m_X(x), m_Y(y), m_zB(zb), m_Solid(solid), m_Char(c) {}

GameObject::~GameObject() {

}

void GameObject::Draw() const {
    StdConio::DrawCharacterInPos(m_X, m_Y, m_Char);
}
