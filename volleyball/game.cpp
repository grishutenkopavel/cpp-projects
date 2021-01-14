#include "include/game.hpp"
#include "include/eventloop.hpp"
#include "include/render.hpp"
#include "include/ball.hpp"

#include <GL/gl.h>
#include <iostream>
void Game::start(SDL_Window *window)
{
    bool running = true;
    Ball ball(0, 0.5, 0.15, -0.01, 0.2);
    while (running)
    {
        running = gLoop.loop();

        glClear(GL_COLOR_BUFFER_BIT);
        ball.move();
        glColor3f(0, 0.5, 0);
        SDL_Delay(50);
        ball.render();
        SDL_GL_SwapWindow(window);
    }

}