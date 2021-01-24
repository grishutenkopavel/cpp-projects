#include <SDL2/SDL.h>
#include "../include/eventloop.hpp"

bool EventLoop::KeyEventHandler(SDL_Event &event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        return false;
        break;
    
    default:
        break;
    }
    return true;
}

void EventLoop::start(bool &runState)
{
    while (SDL_PollEvent(&ev) != 0)
    {
        if(ev.type == SDL_QUIT)
            runState = false;

        runState = KeyEventHandler(ev);
    }
}