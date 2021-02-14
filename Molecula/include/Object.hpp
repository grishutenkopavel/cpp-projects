#pragma once
#include <SDL2/SDL.h>
class Object
{
public:
    virtual void render() = 0;
    virtual bool haveEventHandler() = 0;
    virtual void handleEvent(SDL_Event event) = 0;
};

