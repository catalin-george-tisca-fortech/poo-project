#include "GameEngine.hpp"

#include <chrono>

#include <SDL3/SDL.h>

namespace escape::app {
    struct Transform {
        float x {0.0F};
        float y {0.0F};
    };

    struct RectangleShape {
        float width {0.0F};
        float height {0.0F};
        Color color {};
    };

    struct MoveSpeed {
        float units_per_second {0.0F};
    };


    GameEngine::GameEngine()
        : window_(WindowConfig {.title = "escape engine", .width = 1280, .height = 720}) {}

    void GameEngine::run() {
        bootstrap_demo_scene();
        auto previous_frame_time = std::chrono::steady_clock::now();

        while (window_.is_open()) {
            const auto current_frame_time = std::chrono::steady_clock::now();
            const auto delta_time_seconds =
                std::chrono::duration<float> {current_frame_time - previous_frame_time}.count();
            previous_frame_time = current_frame_time;

            window_.process_events();
            handle_input(delta_time_seconds);
            update(delta_time_seconds);
            render();
        }
    }

    void GameEngine::bootstrap_demo_scene() {
        const auto entity = registry_.create_entity();

        registry_.emplace<Transform>(entity, Transform {.x = 200.0F, .y = 160.0F});
        registry_.emplace<RectangleShape>(entity, RectangleShape {
            .width = 140.0F,
            .height = 100.0F,
            .color = Color {.r = 247, .g = 120, .b = 37, .a = 255},
        });
        registry_.emplace<MoveSpeed>(entity, MoveSpeed {.units_per_second = 320.0F});
    }

    void GameEngine::handle_input(float delta_time_seconds) {
        SDL_PumpEvents();
        const bool* keyboard_state = SDL_GetKeyboardState(nullptr);

        registry_.each<Transform, RectangleShape, MoveSpeed>([&](ecs::Entity, Transform& transform, const RectangleShape& shape, const MoveSpeed& speed) {
            auto horizontal_axis = 0.0F;
            auto vertical_axis = 0.0F;

            if (keyboard_state[SDL_SCANCODE_A]) {
                horizontal_axis -= 1.0F;
            }
            if (keyboard_state[SDL_SCANCODE_D]) {
                horizontal_axis += 1.0F;
            }
            if (keyboard_state[SDL_SCANCODE_W]) {
                vertical_axis -= 1.0F;
            }
            if (keyboard_state[SDL_SCANCODE_S]) {
                vertical_axis += 1.0F;
            }

            transform.x += horizontal_axis * speed.units_per_second * delta_time_seconds;
            transform.y += vertical_axis * speed.units_per_second * delta_time_seconds;

            if (transform.x < 0.0F) {
                transform.x = 0.0F;
            }
            if (transform.y < 0.0F) {
                transform.y = 0.0F;
            }
            if (transform.x + shape.width > static_cast<float>(window_.width())) {
                transform.x = static_cast<float>(window_.width()) - shape.width;
            }
            if (transform.y + shape.height > static_cast<float>(window_.height())) {
                transform.y = static_cast<float>(window_.height()) - shape.height;
            }
        });
    }

    void GameEngine::update(float delta_time_seconds) {
        static_cast<void>(delta_time_seconds);
    }

    void GameEngine::render() {
        window_.clear(Color {.r = 18, .g = 18, .b = 24, .a = 255});

        registry_.each<Transform, RectangleShape>([&](ecs::Entity, const Transform& transform, const RectangleShape& shape) {
            window_.draw_filled_rect(
                Rectangle {
                    .x = transform.x,
                    .y = transform.y,
                    .width = shape.width,
                    .height = shape.height,
                },
                shape.color);
        });

        window_.present();
    }

} 
