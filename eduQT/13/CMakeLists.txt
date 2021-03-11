cmake_minimum_required(VERSION 3.17)

project(calculator)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\")
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(calculator 
                main.cpp
                Calculator.hpp
                Calculator.cpp)

target_link_libraries(calculator ${Qt5Widgets_LIBRARIES})