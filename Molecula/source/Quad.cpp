#include "../include/classes.hpp"

void Quad::render()
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
    glEnd();
}
bool Quad::haveEventHandler()
{
    return false;
}

void Quad::handleEvent(SDL_Event event)
{

}