#include "../include/CoreHandlerSDL.hpp"

SDL_Window *window =nullptr;

void CoreHandlerSDL::initLib()
{
    SDL_GLContext context;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("program", 
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            800, 600,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    
    context = SDL_GL_CreateContext(window);
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glFrustum(-1, 1, -1, 1, -3, 50);

}
int CoreHandlerSDL::eventLoop(std::list<Object*> *objectList)
{
    bool running = true;
    SDL_Event ev;
    std::list<Object*>::iterator iter;
    while(running)
    {
        while(SDL_PollEvent(&ev)!=0)
        {

            if (objectList->front()->haveEventHandler())
            {
                for(iter = objectList->begin(); iter != objectList->end(); iter++)
                {
                    (*iter)->handleEvent(ev);
                }                
            }

            if(ev.type == SDL_QUIT)
            {
                running = false;
            }
            if(ev.type == SDL_KEYDOWN)
            {
                switch (ev.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                
                default:
                    break;
                }
            }

        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        SDL_Delay(16);
        glRotatef(4, 0, 1, 0);
        //render all objects
        for(iter = objectList->begin(); iter != objectList->end(); iter++)
        {
            (*iter)->render();
        }
        SDL_GL_SwapWindow(window);
    }
    return 0;
}

