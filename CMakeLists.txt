cmake_minimum_required(VERSION 3.10)

project(SpaceGame)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.1
)

FetchContent_MakeAvailable(sfml)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(game src/main.cpp src/player.cpp)

target_include_directories(game PRIVATE include)
target_link_libraries(game PRIVATE sfml-graphics)
