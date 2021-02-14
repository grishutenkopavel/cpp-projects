#include "../include/Program.hpp"


Program::Program(/* args */)
{
}

Program::~Program()
{
}

void Program::setProgramCoreHandler(ICoreHandler *coreHandler)
{
    this->coreHandler = coreHandler;
}

int Program::exec()
{
    coreHandler->initLib();
    return coreHandler->eventLoop(&objectList);
}
void Program::addObject(Object *object)
{
    this->object = object;
    objectList.push_back(object);
}