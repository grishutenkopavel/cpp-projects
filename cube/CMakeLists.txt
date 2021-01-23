cmake_minimum_required(VERSION 3.17)

project(cube)

add_executable(cube cube.cpp)

target_link_libraries(cube mingw32 SDL2main SDL2 opengl32)