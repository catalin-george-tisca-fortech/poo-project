#pragma once

#include <memory>
#include <string>

struct SDL_Window;

namespace escape::app {
    struct WindowConfig {
        std::string title {"escape"};
        int width {1280};
        int height {720};
    };

    class Window {
    public:
        explicit Window(WindowConfig config = {});
        ~Window();

        Window(const Window&) = delete;
        Window(Window&&) = delete;
        auto operator=(const Window&) -> Window& = delete;
        auto operator=(Window&&) -> Window& = delete;

        void process_events();

        auto is_open() const noexcept -> bool {
            return is_open_;
        }

        auto native_handle() const noexcept -> SDL_Window* {
            return window_.get();
        }

    private:
        struct WindowDeleter {
            void operator()(SDL_Window* window) const noexcept;
        };

        WindowConfig config_ {};
        std::unique_ptr<SDL_Window, WindowDeleter> window_ {nullptr};
        bool is_open_ {true};
        bool sdl_initialized_ {false};
    };
} 
