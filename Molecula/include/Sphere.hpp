#pragma once
#include "classes.hpp"
typedef struct Color
{
    float r, g, b;
} Color;
class Sphere : public Object
{
private:
    GLUquadricObj *quadObj;
    float x, y, z;
    Color sphereColor = {1 ,1, 1}; 
public:
    Sphere(float x, float y, float z);
    void render() override;
    bool haveEventHandler() override;
    void handleEvent(SDL_Event event) override;

    void setSphereColor(float r, float g, float b);
};
