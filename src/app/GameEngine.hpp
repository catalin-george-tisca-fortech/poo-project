#pragma once

#include "../ecs/Registry.hpp"
#include "Window.hpp"

namespace escape::app {
    class GameEngine {
    public:
        GameEngine();
        ~GameEngine() = default;

        GameEngine(const GameEngine&) = delete;
        GameEngine(GameEngine&&) = delete;
        auto operator=(const GameEngine&) -> GameEngine& = delete;
        auto operator=(GameEngine&&) -> GameEngine& = delete;

        void run();

        auto registry() noexcept -> ecs::Registry& {
            return registry_;
        }

        auto registry() const noexcept -> const ecs::Registry& {
            return registry_;
        }

    private:
        void bootstrap_demo_scene();
        void update();

        Window window_;
        ecs::Registry registry_ {};
    };
}  
