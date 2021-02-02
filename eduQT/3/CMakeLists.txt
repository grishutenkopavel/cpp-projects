cmake_minimum_required(VERSION 3.17)

project(signalMapper)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\")
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets)

add_executable(signalMapper 
                main.cpp 
                include/SomeClass.hpp
                someclass.cpp)

target_link_libraries(signalMapper ${Qt5Widgets_LIBRARIES})