#pragma once
#include "classes.hpp"
class Sphere : public Object
{
private:
    GLUquadricObj *quadObj;
public:
    Sphere();
    void render() override;
    bool haveEventHandler() override;
    void handleEvent(SDL_Event event) override;
};
