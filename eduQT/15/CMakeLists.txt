cmake_minimum_required(VERSION 3.17)

project(htmlLabel)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Widgets)

add_executable(htmlLabel 
                main.cpp
                res.qrc)

target_link_libraries(htmlLabel ${Qt5Widgets_LIBRARIES})