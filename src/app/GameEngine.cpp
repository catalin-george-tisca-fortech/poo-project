#include "GameEngine.hpp"

namespace escape::app {
    struct Position {
        float x {0.0F};
        float y {0.0F};
    };

    struct Velocity {
        float x {0.0F};
        float y {0.0F};
    };

    void GameEngine::run() {
        const auto entity = registry_.create_entity();

        registry_.emplace<Position>(entity, Position {0.0F, 0.0F});
        registry_.emplace<Velocity>(entity, Velocity {1.0F, 1.0F});

        registry_.each<Position, Velocity>([](ecs::Entity, Position& position, const Velocity& velocity) {
            position.x += velocity.x;
            position.y += velocity.y;
        });
    }

}  
