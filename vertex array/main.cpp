#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "include/arrays.h"

SDL_Window *window = nullptr;
void drawCube()
{
    glColor3f(1,1,0);
    glBegin( GL_QUADS );
            glVertex2f( -0.5f, -0.5f );
            glVertex2f( 0.5f, -0.5f );
            glVertex2f( 0.5f, 0.5f );
            glVertex2f( -0.5f, 0.5f );
    glEnd();
}
void draw()
{
    glVertexPointer(2, GL_FLOAT, 0, &vertex);
    glEnableClientState(GL_VERTEX_ARRAY);
        glColor3f(1,1,0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);   
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