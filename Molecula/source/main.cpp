#include "../include/classes.hpp"
#include "../include/CoreHandlerSDL.hpp"
int main(int argc, char *argw[])
{
    Program *molecula = new Program();  
    molecula->setProgramCoreHandler(new CoreHandlerSDL);
    Quad q;
    molecula->addObject(&q);

    return molecula->exec();
}