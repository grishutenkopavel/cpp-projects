#include "../include/classes.hpp"

Quad::Quad(float x, float y, float z, float w, float h)
    :
    x(x),
    y(y),
    z(z),
    w(w),
    h(h) {}

void Quad::render()
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y+h);
        glVertex2f(x+w, y+h);
        glVertex2f(x+w, y);
        glVertex2f(x, y);
    glEnd();
}
bool Quad::haveEventHandler()
{
    return false;
}

void Quad::handleEvent(SDL_Event event)
{

}