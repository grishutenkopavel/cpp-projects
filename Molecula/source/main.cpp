#include "../include/classes.hpp"
#include "../include/CoreHandlerSDL.hpp"

class RotatingQuad : public Quad
{
private:
    /* data */
public:
    RotatingQuad(float x, float y, float z, float w, float h) : Quad(x, y, z, w, h) {}
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
    //RotatingQuad q(0,0,0,1,1);
    Sphere s1(0.6, 0, 5);
    s1.setSphereColor(1, 0, 0);
    Sphere s2(-0.6, 0, 5);
    s2.setSphereColor(0, 1, 0);
    molecula->addObject(&s1);
    molecula->addObject(&s2);

    return molecula->exec();
}