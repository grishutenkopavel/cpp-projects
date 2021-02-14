#pragma once

#include <SDL2/SDL.h>
#include "classes.hpp"

class CoreHandlerSDL : public ICoreHandler
{
private:

public:
    void initLib() override;
    int eventLoop(std::list<Object*> *objectList) override;
};

