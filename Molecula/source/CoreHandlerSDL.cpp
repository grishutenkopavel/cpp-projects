#include "../include/CoreHandlerSDL.hpp"

SDL_Window *window =nullptr;

void CoreHandlerSDL::initLib()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("program", 
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            800, 600,
                            SDL_WINDOW_SHOWN);
}
int CoreHandlerSDL::eventLoop()
{
    SDL_Delay(5000);
    return 0;
}

