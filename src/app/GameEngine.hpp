#pragma once

#include "../ecs/Registry.hpp"

namespace escape::app {

class GameEngine {
public:
    GameEngine() = default;
    ~GameEngine() = default;

    GameEngine(const GameEngine&) = delete;
    GameEngine(GameEngine&&) noexcept = default;
    auto operator=(const GameEngine&) -> GameEngine& = delete;
    auto operator=(GameEngine&&) noexcept -> GameEngine& = default;

    void run();

    auto registry() noexcept -> ecs::Registry& {
        return registry_;
    }

    auto registry() const noexcept -> const ecs::Registry& {
        return registry_;
    }

private:
    ecs::Registry registry_ {};
};

}  // namespace escape::app
