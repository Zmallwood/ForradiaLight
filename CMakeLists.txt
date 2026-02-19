cmake_minimum_required(VERSION 3.5)

project(Forradia LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_SOURCES
    "./src/*.cpp"
)

add_executable(Forradia ${SRC_SOURCES})

target_include_directories(Forradia
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_precompile_headers(Forradia
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src/StdAfx.hpp"
)

target_link_libraries(Forradia
    PUBLIC
        SDL2
        SDL2_image
        SDL2_ttf
)