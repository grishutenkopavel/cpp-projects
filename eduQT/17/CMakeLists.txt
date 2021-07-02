cmake_minimum_required(VERSION 3.17)

project(progressbar)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\")
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(progressbar 
                main.cpp
                Progress.cpp
                )

target_link_libraries(progressbar ${Qt5Widgets_LIBRARIES})