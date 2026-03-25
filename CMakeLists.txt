cmake_minimum_required(VERSION 3.16)

project(escape VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(escape
    src/main.cpp
    src/app/GameEngine.cpp
)

target_include_directories(escape
    PRIVATE
        src
)
