#pragma once
#include "classes.hpp"
class ICoreHandler
{
public:
    virtual void initLib() = 0;
    virtual int eventLoop(std::list<Object*> *objectList) = 0;
};
