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
}
int CoreHandlerSDL::eventLoop(std::list<Object*> *objectList)
{
    bool running = true;
    SDL_Event ev;
    while(running)
    {
        while(SDL_PollEvent(&ev)!=0)
        {

            //take object with EventsHanler and handleEvent()
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

        objectList->front()->render();//render all objects
        SDL_GL_SwapWindow(window);
    }
    return 0;
}

