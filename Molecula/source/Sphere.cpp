#include "../include/classes.hpp"
Sphere::Sphere()
{
    quadObj = gluNewQuadric();
}
void Sphere::render()
{
    gluSphere(quadObj, 0.5, 10, 10);
}
bool Sphere::haveEventHandler()
{
    return false;
}
void Sphere::handleEvent(SDL_Event event)
{

}