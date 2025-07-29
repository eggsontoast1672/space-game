cmake_minimum_required(VERSION 3.10)
project(SpaceGame)

# This project uses Raylib version 3.7.0 which relies on an old version of
# CMake. This is needed in order to compile.
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(OpenGL_GL_PREFERENCE GLVND)

add_subdirectory(lib/raylib)
add_executable(
  game
  src/background.cpp
  src/bullet.cpp
  src/collisionhandler.cpp
  src/collisionobjects.cpp
  src/enemy.cpp
  src/enemyspawner.cpp
  src/globals.cpp
  src/main.cpp
  src/musicplayer.cpp
  src/player.cpp
  src/scoredisplay.cpp
)

set_property(TARGET game PROPERTY COMPILE_OPTIONS -Wall -Wno-missing-braces)
set_property(TARGET game PROPERTY INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include)
set_property(TARGET game PROPERTY LINK_LIBRARIES raylib)
