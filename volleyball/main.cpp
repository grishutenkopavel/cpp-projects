#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "include/game.hpp"
#include "include/eventloop.hpp"
#include "include/constants.hpp"
#include "include/player.hpp"
#include "include/ball.hpp"

#define WIN_HEIGHT 700
#define WIN_WIDTH 1200

SDL_Window *window = NULL;
int init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return -1;
    }
    window = SDL_CreateWindow("game",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            WIN_WIDTH, WIN_HEIGHT,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        return -1;
    }
    SDL_GLContext context = SDL_GL_CreateContext(window);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glScalef(WIN_HEIGHT/float(WIN_WIDTH), 1, 1);
    return 0;
}

int main( int argc, char *argv[] )
{
    
    if ( init( ) < 0 )
    {
        return 0;
    }

    Game game;
    game.start(window);
    return 0;
}

