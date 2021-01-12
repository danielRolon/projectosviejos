#pragma once

#include <list>
#include <memory>

#include "objects/gameObject.h"

namespace ECS {
    class EntityManager {
    public:
        EntityManager(int);
        void MainLoop();
        void AddObject(GameObject*);
        void DeleteObject(GameObject*);
    private:
        void Update();
        void Draw() const;

        std::list<std::unique_ptr<GameObject>> m_Objects {};
    };
}