#include "../include/classes.hpp"
#include "../include/CoreHandlerSDL.hpp"
int main(int argc, char *argw[])
{
    Program *molecula = new Program();  
    molecula->setProgramCoreHandler(new CoreHandlerSDL);
    
    //-> addObjects()

    return molecula->exec();
}