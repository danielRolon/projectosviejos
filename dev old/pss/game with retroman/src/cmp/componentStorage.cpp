#include <cmp/componentStorage.h>

namespace ECS {

    ComponentStorage::ComponentStorage(std::size_t MaxComponents) {
        m_Components.reserve(MaxComponents);
    }

    PhysicsComponent& ComponentStorage::AddComponent() {
        auto& cmp = m_Components.emplace_back();
        return cmp;
    }
} // namespace ECS