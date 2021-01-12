#include "ECS.h"

#include "objects/player.h"

namespace ECS {

    EntityManager::EntityManager(int MaxObjectsCount) {
        m_Objects.resize(MaxObjectsCount);
    }

    void EntityManager::MainLoop() {

    }

    void EntityManager::Update() {
        std::list<std::unique_ptr<GameObject>>::iterator p;
        while (p != m_Objects.end()) {
            p->get()->Update();
        } 
    }

    void EntityManager::Draw() const {
        std::list<std::unique_ptr<GameObject>>::iterator p;
        while (++p != m_Objects.end()) {
            p->get()->Update();
        } 
    }

    void EntityManager::AddObject(GameObject* object) {
        std::unique_ptr<Player> o {new Player(0, 0)};
        m_Objects.emplace_back(object);
    }

    void EntityManager::DeleteObject(GameObject* object) {
        m_Objects.remove(std::make_unique<Player>(object));
    }

} // ECS
