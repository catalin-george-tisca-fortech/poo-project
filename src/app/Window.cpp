#include "Window.hpp"

#include <stdexcept>

#include <SDL3/SDL.h>

namespace escape::app {
    auto make_window_error(const char* message) -> std::runtime_error {
        return std::runtime_error {std::string {message} + ": " + SDL_GetError()};
    }

    Window::Window(WindowConfig config)
        : config_(std::move(config)) {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            throw make_window_error("Failed to initialize SDL video");
        }

        sdl_initialized_ = true;
        window_.reset(SDL_CreateWindow(config_.title.c_str(), config_.width, config_.height, SDL_WINDOW_RESIZABLE));

        if (window_ == nullptr) {
            SDL_Quit();
            sdl_initialized_ = false;
            throw make_window_error("Failed to create SDL window");
        }
    }

    Window::~Window() {
        window_.reset();

        if (sdl_initialized_) {
            SDL_Quit();
        }
    }

    void Window::process_events() {
        SDL_Event event {};

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                is_open_ = false;
                break;
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                if (event.window.windowID == SDL_GetWindowID(window_.get())) {
                    is_open_ = false;
                }
                break;
            default:
                break;
            }
        }
    }

    void Window::WindowDeleter::operator()(SDL_Window* window) const noexcept {
        if (window != nullptr) {
            SDL_DestroyWindow(window);
        }
    }
} 
