cmake_minimum_required(VERSION 3.10)
project(SpaceGame)

add_subdirectory(lib/SDL)
add_subdirectory(lib/SDL_image)

add_executable(game src/main.c)
target_link_libraries(game SDL3::SDL3 SDL3_image::SDL3_image)
