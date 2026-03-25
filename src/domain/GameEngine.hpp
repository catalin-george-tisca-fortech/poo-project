#pragma once

class GameEngine {
public:
    GameEngine() = default;
    ~GameEngine() = default;

    GameEngine(const GameEngine&) = default;
    GameEngine(GameEngine&&) noexcept = default;
    auto operator=(const GameEngine&) -> GameEngine& = default;
    auto operator=(GameEngine&&) noexcept -> GameEngine& = default;

    void run();
};
