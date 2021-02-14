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