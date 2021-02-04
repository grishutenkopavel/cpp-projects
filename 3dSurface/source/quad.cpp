#include <GL/gl.h>
#include "../include/quad.hpp"

Quad::Quad(float x, float y, float width, float height)
    :
    x_(x),
    y_(y),
    w_(width),
    h_(height),
    colorVec({0, 0.5, 0}) {}

void Quad::setColor(float r, float g, float b)
{
    colorVec[0] = r;
    colorVec[1] = g;
    colorVec[2] = b;
}
void Quad::draw()
{
    glColor3f(colorVec[0], colorVec[1], colorVec[2]);
    glBegin(GL_QUADS);
        glVertex3f(x_, y_, 0);
        glVertex3f(x_, y_ - h_, 0);
        glVertex3f(x_ - h_, y_ - h_, 0);
        glVertex3f(x_ - h_, y_, 0);
    glEnd();
}