#include "../include/classes.hpp"
Sphere::Sphere(float x, float y, float z)
    :
    x(x),
    y(y),
    z(z)
{
    quadObj = gluNewQuadric();
}
void Sphere::render()
{
    GLfloat front_color[] = {0,1,0,1};
    GLfloat back_color[] = {0,0,1,1};
    glPushMatrix();
    glTranslatef(x, 0, 0);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, front_color);
    //glMaterialfv(GL_BACK, GL_DIFFUSE, back_color);
    glColor3f(sphereColor.r, sphereColor.g, sphereColor.b);
    gluSphere(quadObj, 0.5, 100, 100);
    glPopMatrix();
}
bool Sphere::haveEventHandler()
{
    return false;
}
void Sphere::handleEvent(SDL_Event event)
{

}

void Sphere::setSphereColor(float r, float g, float b)
{
    sphereColor.r = r;
    sphereColor.g = g;
    sphereColor.b = b;
}