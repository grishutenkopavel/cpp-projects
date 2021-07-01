#pragma once 

#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "PlayGround.hpp"
#include "structures.h"

class Game
{
private:
    SDL_Window* window = nullptr;
    WindowSize size;
    int errorStatus;
    PlayGround* gameField;

private:
    void newGame();

public:
    Game( int cellsVertically, int cellsHorizontally );
    int init();
    int start();
    void reactToWindowEvent( SDL_Event* event, bool* programStatus );
    void eventLoop();
    ~Game();
};
