#include "include/game.hpp"
#include "include/eventloop.hpp"
#include "include/constants.hpp"
#include "include/ball.hpp"

#include <GL/gl.h>
#include <iostream>
#include "include/game.hpp"
void Game::start(SDL_Window *window)
{
    bool running = true;
    while (running)
    {
        running = gLoop.loop(&player1, &player2);
        renderer.show(window, &ball, &player1, &player2);
    }

}