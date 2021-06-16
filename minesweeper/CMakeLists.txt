cmake_minimum_required(VERSION 3.17)

project(window)

add_executable(window example.c)

target_link_libraries(window user32 opengl32)