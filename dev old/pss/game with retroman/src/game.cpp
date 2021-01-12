#include "game.h"

#include <keyboardMan.h>
#include <StdConio.h>
#include <memory>

#include <objects/entity.h>

Game::Game()
    : em(128) {
    m_Running = true;
    m_KeyMan = KeyboardMan::GetKeyboardMan();
    StdConio::Hidecursor(true);

    em.AddObject(5, 5, 0, 'E');
}

Game::~Game() {
    delete m_KeyMan;
    m_KeyMan = nullptr;
}

void Game::MainLoop() {
    while(m_Running) {
        StdConio::Clear();

        rm.Loop(em);        // Update render

        m_KeyMan->Update(); // Update keyboard manager

        em.Loop();          // Update entity manager

        pm.Loop(em);        // Update physics manager

        cm.Loop(em);        // Update collision manager

        if (m_KeyMan->GetLastkeyPressed() == VK_ESCAPE) m_Running = false;
    }

    StdConio::Clear();
}
