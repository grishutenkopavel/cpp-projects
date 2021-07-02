cmake_minimum_required(VERSION 3.17)

project(QLCDNumber)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\")
# set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(QLCDNumber 
                main.cpp
                )

target_link_libraries(QLCDNumber ${Qt5Widgets_LIBRARIES})