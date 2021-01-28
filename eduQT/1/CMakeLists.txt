cmake_minimum_required(VERSION 3.17)

project(hello)

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.10\\mingw73_64\\") #set path

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(hello main.cpp)

target_link_libraries(hello ${Qt5Widgets_LIBRARIES})

