#pragma once

class ICoreHandler
{
public:
    virtual void initLib() = 0;
    virtual int eventLoop() = 0;
};
