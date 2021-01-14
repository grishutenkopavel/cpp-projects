#include "include/game.hpp"
#include "include/eventloop.hpp"
#include "include/render.hpp"
#include "include/ball.hpp"

#include <GL/gl.h>
void Game::start(SDL_Window *window)
{
    bool running = true;
    Ball ball(0, 0, 0, 0, 0.2);
    while (running)
    {
        running = gLoop.loop();
        glColor3f(0, 0.5, 0);
        ball.render(30);
        SDL_GL_SwapWindow(window);
    }

}