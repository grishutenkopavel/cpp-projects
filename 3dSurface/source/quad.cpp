#include <GL/gl.h>
#include "../include/quad.hpp"

Quad::Quad(float x, float y, float width, float height)
    :
    x_(x),
    y_(y),
    w_(width),
    h_(height) {}

void Quad::draw()
{
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        glVertex3f(x_, y_, 0);
        glVertex3f(x_, y_ - h_, 0);
        glVertex3f(x_ - h_, y_ - h_, 0);
        glVertex3f(x_ - h_, y_, 0);
    glEnd();
    glPushMatrix();
        glRotatef(-20, 1, 0, 0);
    glPopMatrix();
}