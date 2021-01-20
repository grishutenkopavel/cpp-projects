cmake_minimum_required(VERSION 3.17)

project(game)

add_executable(game main.cpp)

target_link_libraries(game mingw32 SDL2main SDL2 opengl32)