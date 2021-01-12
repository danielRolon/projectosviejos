#pragma once

#include <utils/aliases.h>
#include <objects/entity.h>
#include <sys/contextGame.h>

#include <cmp/componentStorage.h>

namespace ECS {
    class EntityManager : public ContextGame {
    public:
        explicit EntityManager();
        EntityManager(int);
        void Loop();
        void AddObject(int x, int y, int zb, char c);
        const VectorEntities& GetEntities() const override { return m_Entities; }
              VectorEntities& GetEntities()       override { return m_Entities; }
        const std::vector<ECS::PhysicsComponent>& GetComponents() const override { return m_CmpStorage.GetComponents(); }
              std::vector<ECS::PhysicsComponent>& GetComponents()       override { return m_CmpStorage.GetComponents(); }
    private:
        static constexpr std::size_t MAX_ENTITIES = 128;
        VectorEntities m_Entities {};
        ComponentStorage m_CmpStorage { MAX_ENTITIES };
    };
}