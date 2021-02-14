#pragma once

#include <SDL2/SDL.h>
#include "classes.hpp"

class CoreHandlerSDL : public ICoreHandler
{
private:
    /* data */
public:
    void initLib() override;
    int eventLoop() override;
};

