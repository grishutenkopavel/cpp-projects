cmake_minimum_required(VERSION 3.17)

project(surface)

add_executable(surface source/main.cpp source/window.cpp source/eventloop.cpp)

target_link_libraries(surface mingw32 SDL2main SDL2 opengl32)