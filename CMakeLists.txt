cmake_minimum_required(VERSION 3.16)

project(escape VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

execute_process(
    COMMAND brew --prefix sdl3
    OUTPUT_VARIABLE SDL3_BREW_PREFIX
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

if(SDL3_BREW_PREFIX)
    list(PREPEND CMAKE_PREFIX_PATH "${SDL3_BREW_PREFIX}")
endif()

find_package(SDL3 CONFIG REQUIRED)

add_executable(escape
    src/main.cpp
    src/app/GameEngine.cpp
    src/app/Window.cpp
    src/game/Vector2.cpp
    src/game/Size2D.cpp
    src/game/RenderStyle.cpp
    src/game/PlayerRectangle.cpp
)

target_include_directories(escape
    PRIVATE
        src
)

target_link_libraries(escape
    PRIVATE
        SDL3::SDL3
)
