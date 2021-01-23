cmake_minimum_required(VERSION 3.17)

project(glperspective)

add_executable(glperspective main.cpp)

target_link_libraries(glperspective mingw32 SDL2main SDL2 opengl32)