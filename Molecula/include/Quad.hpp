#pragma once
#include "classes.hpp"

class Quad : public Object
{
private:
    float x, y, z;
    float w, h;
public:
    Quad(float x, float y, float z, float w, float h);
    void render() override;
    bool haveEventHandler() override;
    void handleEvent(SDL_Event event) override;
};
