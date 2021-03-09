cmake_minimum_required(VERSION 3.17)

project(ScrollBars)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Widgets)

add_executable(ScrollBars 
                main.cpp res.qrc)

target_link_libraries(ScrollBars ${Qt5Widgets_LIBRARIES})