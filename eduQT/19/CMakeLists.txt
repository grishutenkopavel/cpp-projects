cmake_minimum_required(VERSION 3.17)

project(OGLPyramid)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\")
# set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(OGLPyramid 
                main.cpp
                OGLPyramid.cpp
                )

target_link_libraries(OGLPyramid opengl32 ${Qt5Widgets_LIBRARIES})