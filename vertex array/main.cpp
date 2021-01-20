#include <SDL2/SDL.h>
#include <GL/gl.h>

SDL_Window *window = nullptr;

void draw()
{
    glColor3f(1,1,0);
    glBegin( GL_QUADS );
            glVertex2f( -0.5f, -0.5f );
            glVertex2f( 0.5f, -0.5f );
            glVertex2f( 0.5f, 0.5f );
            glVertex2f( -0.5f, 0.5f );
    glEnd();;
}

void init(int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            width, height,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);
    glClearColor(0, 0, 0, 0);  
}

void eventLoop()
{
    SDL_Event ev;
    bool running = true;
    while(running)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
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
        draw();
         SDL_GL_SwapWindow(window);
    }
    
}

int main(int argc, char *argv[])
{
    init(500, 500);
    eventLoop();
    return 0;
}