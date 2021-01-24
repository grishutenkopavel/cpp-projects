#include "../include/window.hpp"
#include <SDL2/SDL.h>
#include <GL/gl.h>

SDL_Window *window = nullptr;

Window::Window(int width, int height)
    :
    width_(width),
    height_(height) 
{
        bool success = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        status = !success;
    }
    window = SDL_CreateWindow("Cube",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            width_, height_, 
                            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(window == nullptr)
    {
        status = !success;
    }

    context = SDL_GL_CreateContext(window);
    glClearColor(0, 0, 0, 0);
    // glEnable(GL_DEPTH_TEST);
    status = success;
}

void Window::show()
{
    bool running = true;
    while(running)
    {
        el.start(running);
        SDL_GL_SwapWindow(window);
        //render.start
    }
}

Window::~Window()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    window = nullptr;
}

