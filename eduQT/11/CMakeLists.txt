cmake_minimum_required(VERSION 3.17)

project(HVLayout)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\")
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(HVLayout 
                main.cpp)

target_link_libraries(HVLayout ${Qt5Widgets_LIBRARIES})