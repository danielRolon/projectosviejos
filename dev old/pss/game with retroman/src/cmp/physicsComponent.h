#pragma once

namespace ECS {
    struct PhysicsComponent {
        explicit PhysicsComponent() = default;

        ~PhysicsComponent() {}

        int x {0}, y {0}, vx {0}, vy {0};
    };
} // namespace ECS