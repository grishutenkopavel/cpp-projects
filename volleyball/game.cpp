#include "include/game.hpp"
#include "include/eventloop.hpp"
#include "include/constants.hpp"
#include "include/ball.hpp"

#include <GL/gl.h>
#include <iostream>
void Game::drawCube(float x, float y, float dx, float dy)
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        glVertex2f(x+dx, y);
        glVertex2f(x+dx, y+dy);
        glVertex2f(x, y+dy);
    glEnd();
}
void Game::renderBackground()
{
    glColor3f(0.83, 0.81, 0.67);
    drawCube(-(float)1200/700, -1, (float)1200/700*2, 1);
    glColor3f(0.21, 0.67, 0.88);
    drawCube(-(float)1200/700, 0, (float)1200/700*2, 1);
    glColor3f(0.66, 0.85, 1);
    drawCube(-(float)1200/700, 0.2, (float)1200/700*2, 1);
}
void Game::renderGrid()
{
    glColor3f(0, 0, 0);
    glLineWidth(8);
    glBegin(GL_LINES);
        glVertex2f(0, GRID_HEIGHT);
        glVertex2f(0, -1);
    glEnd();
}
void Game::start(SDL_Window *window)
{
    bool running = true;
    Ball ball(0, 0.5, 0.15, -0.01, 0.2);
    while (running)
    {
        running = gLoop.loop();

        glClear(GL_COLOR_BUFFER_BIT);
        ball.move();
        renderBackground();
        renderGrid();
        glColor3f(0, 0.5, 0);
        SDL_Delay(50);
        ball.render();
        SDL_GL_SwapWindow(window);
    }

}