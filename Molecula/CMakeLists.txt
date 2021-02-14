cmake_minimum_required(VERSION 3.17)

project(Molecula)

add_executable(Molecula
                source/main.cpp
                source/CoreHandlerSDL.cpp
                source/Quad.cpp
                source/Sphere.cpp
                source/Program.cpp)

if (WIN32)
    target_link_libraries(Molecula mingw32 SDL2main SDL2 opengl32 glu32)
endif (WIN32)
