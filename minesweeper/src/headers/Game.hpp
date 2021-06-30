#pragma once 

#include <SDL2/SDL.h>

typedef struct{
    int width;
    int height;
}  WindowSize;


class Game
{
private:
    SDL_Window* window = nullptr;
    WindowSize size;
    int errorStatus;  
public:
    Game(/* args */);
    int init();
    int start();
    void eventLoop();
    ~Game();
};
