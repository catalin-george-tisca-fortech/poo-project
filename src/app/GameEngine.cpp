#include "GameEngine.hpp"

#include <chrono>
#include <thread>

namespace escape::app {
    struct Position {
        float x {0.0F};
        float y {0.0F};
    };

    struct Velocity {
        float x {0.0F};
        float y {0.0F};
    };


    GameEngine::GameEngine()
        : window_(WindowConfig {.title = "escape engine", .width = 1280, .height = 720}) {}

    void GameEngine::run() {
        bootstrap_demo_scene();

        while (window_.is_open()) {
            window_.process_events();
            update();
            std::this_thread::sleep_for(std::chrono::milliseconds {16});
        }
    }

    void GameEngine::bootstrap_demo_scene() {
        const auto entity = registry_.create_entity();
        registry_.emplace<Position>(entity, Position {0.0F, 0.0F});
        registry_.emplace<Velocity>(entity, Velocity {1.0F, 1.0F});
    }

    void GameEngine::update() {
        registry_.each<Position, Velocity>([](ecs::Entity, Position& position, const Velocity& velocity) {
            position.x += velocity.x;
            position.y += velocity.y;
        });
    }
}
