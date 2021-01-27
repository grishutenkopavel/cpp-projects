#include <GL/gl.h>
#include "../include/renderer.hpp"
#include "../include/object.hpp"
void Renderer::start()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    camera.move();
    for(objectsIter = objects.begin(); objectsIter != objects.end(); objectsIter++)
    {
        (*objectsIter)->draw();
    }
    glPopMatrix();
}

void Renderer::addObject(Object *whatToRender)
{
    objects.push_back(whatToRender);
}