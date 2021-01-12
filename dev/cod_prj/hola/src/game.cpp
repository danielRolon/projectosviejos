#include "game.h"

#include "keyboardMan.h"
#include "StdConio.h"

#include "objects/player.h"

Game::Game() {
    m_Running = true;
    m_KeyMan = KeyboardMan::GetKeyboardMan();
    StdConio::Hidecursor(true);

    m_Objects.reserve(100);
    m_Objects.push_back(std::make_unique<Player>(5, 5));
    m_Objects.push_back(std::make_unique<Player>(7, 5));
    m_Objects.push_back(std::make_unique<Player>(8, 6));
}

Game::~Game() {
    delete m_KeyMan;
    m_KeyMan = nullptr;
}

void Game::MainLoop() {
    while(m_Running) {
        Draw();
        Update();
    }

    StdConio::Clear();
}

void Game::Draw() {
    StdConio::Clear();

    for (uint32_t i = 0; i < m_Objects.size(); i++) {
        m_Objects[i]->Draw();
    }
}

void Game::Update() {
    m_KeyMan->Update();

    for (uint32_t i = 0; i < m_Objects.size(); i++) {
        m_Objects[i]->Update();
    }

    if (m_KeyMan->GetLastkeyPressed() == VK_ESCAPE) m_Running = false;
}
