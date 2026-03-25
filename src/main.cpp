#include "app/GameEngine.hpp"

#include <exception>
#include <iostream>

int main() {
    try {
        auto engine = escape::app::GameEngine {};
        engine.run();
        return 0;
    } catch (const std::exception& exception) {
        std::cerr << "escape failed to start: " << exception.what() << '\n';
        return 1;
    }
}
