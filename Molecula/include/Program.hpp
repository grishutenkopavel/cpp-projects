#pragma once

#include "classes.hpp"

class Program
{
private:
    std::list<Object*> objectList;
    ICoreHandler *coreHandler;
    Object *object;
public:
    Program(/* args */);
    ~Program();
    void setProgramCoreHandler(ICoreHandler *coreHandler);
    void addObject(Object *object);
    int exec();
};

