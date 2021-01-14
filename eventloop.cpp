#include <SDL2/SDL.h>
#include "include/eventloop.hpp"

bool EventLoop::loop()
{
    while(SDL_PollEvent(&ev) != 0)
    {
        if (ev.type == SDL_QUIT)
            return false;
    }
    return true;
}