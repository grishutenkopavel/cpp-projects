#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <list>
#include "object.hpp"
#include "camera.hpp"
class Renderer
{
private:
    Camera camera;
    std::list<Object*> objects;
    std::list<Object*>::iterator objectsIter;
public:
    void start();
    void addObject(Object *whatToRender);
};

#endif