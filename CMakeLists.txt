cmake_minimum_required(VERSION 3.31)

project(real_engine)

set(CMAKE_CXX_STANDARD 17)

# SETUP SDL 2
set(SDL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/rengine/third_party/SDL2")
set(SDL_INCLUDE_DIR "${SDL_PATH}/include")
set(SDL_LIB_DIR "${SDL_PATH}/lib/x64")

add_subdirectory(rengine)

add_subdirectory(game)


