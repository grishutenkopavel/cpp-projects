#include <SDL2/SDL.h>
#include "include/constants.hpp"
#include "include/eventloop.hpp"
#include "include/player.hpp"
#include "include/render.hpp"
bool EventLoop::loop(Player *player1, Player *player2)
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

            case SDLK_a:
                player1->playerMove(SDLK_a, -KOEF, 0);
                break;
            case SDLK_d:
                player1->playerMove(SDLK_d, -KOEF, 0);
                break;

            case SDLK_LEFT:
                player2->playerMove(SDLK_LEFT, 0, KOEF);
                break;
            case SDLK_RIGHT:
                player2->playerMove(SDLK_RIGHT, 0, KOEF);
                break;
            
            default:
                break;
            }
        }
    }
    return true;
}