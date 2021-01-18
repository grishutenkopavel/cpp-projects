#include "include/constants.hpp"
#include "include/render.hpp"
#include <SDL2/SDL.h>
#include <GL/gl.h>

void Render::drawCube(float x, float y, float dx, float dy)
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        glVertex2f(x+dx, y);
        glVertex2f(x+dx, y+dy);
        glVertex2f(x, y+dy);
    glEnd();
}
void Render::renderBackground()
{
    glColor3f(0.83, 0.81, 0.67);
    drawCube(-KOEF, -1, KOEF*2, 1);
    glColor3f(0.21, 0.67, 0.88);
    drawCube(-KOEF, 0, KOEF*2, 1);
    glColor3f(0.66, 0.85, 1);
    drawCube(-KOEF, 0.2, KOEF*2, 1);
}
void Render::renderGrid()
{
    glColor3f(0, 0, 0);
    glLineWidth(8);
    glBegin(GL_LINES);
        glVertex2f(0, GRID_HEIGHT);
        glVertex2f(0, -1);
    glEnd();
}

void Render::show(SDL_Window *window, Ball *ball, Player *player1, Player *player2)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    ball->move();
    player1->playerMove(-KOEF, 0);
    player2->playerMove(0, KOEF);
    ball->checkCollision(&player1->x, &player1->y, &player1->r);
    ball->checkCollision(&player2->x, &player2->y, &player2->r);
    renderBackground();
    renderGrid();
    SDL_Delay(35);
    glColor3f(0, 0.5, 0);
    ball->render();

    glColor3f(0.8, 0, 0);
    player1->render();
    glColor3f(0.23, 0.29, 0.79);
    player2->render();
    SDL_GL_SwapWindow(window);
}