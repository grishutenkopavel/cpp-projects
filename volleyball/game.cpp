#include "include/game.hpp"
#include "include/eventloop.hpp"
#include "include/constants.hpp"
#include "include/ball.hpp"

#include <GL/gl.h>
#include <iostream>

void Game::start(SDL_Window *window)
{
    bool running = true;
    while (running)
    {
        running = gLoop.loop();
        renderer.show(window);
    }

}