#include <SDL2/SDL.h>
#include "include/eventloop.hpp"
#include "include/player.hpp"
#include "include/render.hpp"
bool EventLoop::loop()
{
    while(SDL_PollEvent(&ev) != 0)
    {
        if (ev.type == SDL_QUIT)
            return false;
        if (ev.type == SDL_KEYDOWN)
        {
            switch (ev.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                return false;
                break;
            
             case SDLK_LEFT:
                //player1.
                break;

            default:
                break;
            }
        }
    }
    return true;
}