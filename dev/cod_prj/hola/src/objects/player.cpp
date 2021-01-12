#include "objects/player.h"

#include "keyboardMan.h"

Player::Player(unsigned int x, unsigned int y)
    : GameObject(x, y, 1, true, 'P') {

}

void Player::Update() {
    m_X += bool(KeyboardMan::GetLastkeyPressed() == 'd') - bool(KeyboardMan::GetLastkeyPressed() == 'a');
    m_Y += bool(KeyboardMan::GetLastkeyPressed() == 's') - bool(KeyboardMan::GetLastkeyPressed() == 'w');
}

void Player::Draw() const {
    GameObject::Draw();
}
