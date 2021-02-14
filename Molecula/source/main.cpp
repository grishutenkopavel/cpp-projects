#include "../include/classes.hpp"
#include "../include/CoreHandlerSDL.hpp"

class RotatingQuad : public Quad
{
private:
    /* data */
public:
    bool haveEventHandler() override
    {
        return true;
    }
    void handleEvent(SDL_Event event) override
    {
        if(event.type == SDL_KEYDOWN)
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            glRotatef(3, 0, 0, 1);
            break;
        case SDLK_RIGHT:
            glRotatef(3, 0, 0, -1);
            break;
        default:
            break;
        }
    }

};


int main(int argc, char *argw[])
{
    Program *molecula = new Program();  
    molecula->setProgramCoreHandler(new CoreHandlerSDL);
    RotatingQuad q;
    molecula->addObject(&q);

    return molecula->exec();
}