#pragma once
#include "classes.hpp"

class Quad : public Object
{
private:
    
public:
    void render() override;
    bool haveEventHandler() override;
    void handleEvent(SDL_Event event) override;
};
