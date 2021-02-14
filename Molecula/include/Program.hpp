#pragma once

#include "ICoreHandler.hpp"

class Program
{
private:
    ICoreHandler *coreHandler;
public:
    Program(/* args */);
    ~Program();
    void setProgramCoreHandler(ICoreHandler *coreHandler);
    int exec();
};

