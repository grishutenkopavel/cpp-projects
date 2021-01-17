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
                player1->isLeft = true;
                break;
            case SDLK_d:
                player1->isRight = true;
                break;
            case SDLK_w:
                player1->isJump = true;
                break;
            case SDLK_LEFT:
                player2->isLeft = true;
                break;
            case SDLK_RIGHT:
                player2->isRight = true;
                break;
            case SDLK_UP:
                player2->isJump = true;
                break;
            
            default:
                break;
            }
        }
        if (ev.type == SDL_KEYUP)
        {
            switch (ev.key.keysym.sym)
            {
            case SDLK_a:
                player1->isLeft = false;
                break;
            case SDLK_d:
                player1->isRight = false;
                break;
            case SDLK_w:
                player1->isJump = false;
                break;
            case SDLK_LEFT:
                player2->isLeft = false;
                break;
            case SDLK_RIGHT:
                player2->isRight = false;
                break;
            case SDLK_UP:
                player2->isJump = false;
                break;
            
            default:
                break;
            }
        }
    }
    return true;
}