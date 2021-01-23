#include <SDL2/SDL.h>
#include <GL/gl.h>

SDL_Window *window = nullptr;

float redTriangle[]= {
    -1, 0, 1,
    1, 1, 0,
    1, -1, 0
};

float greenTriangle[]= {
    1, 0, 1,
    -1, 1, 0,
    -1, -1, 0
};

bool init(int witdh, int height);
void eventLoop();
void close();

void drawGreenTriangle();
void drawRedTriangle();

bool init(int witdh, int height)
{
    SDL_GLContext context;
    bool success = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return !success;
    }
    window = SDL_CreateWindow("Perspective",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            witdh, height, 
                            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(window == nullptr)
    {
        return !success;
    }

    context = SDL_GL_CreateContext(window);
    glClearColor(0, 0, 0, 0);

    return success;
}

void eventLoop()
{
    SDL_Event ev;
    bool running = true;

    glFrustum(-2,2, -1,1, 0,3);
    while(running)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
            if(ev.type == SDL_QUIT)
                running = false;
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
        drawRedTriangle();
        drawGreenTriangle();
        glTranslatef(0,0,-0.01);
        glRotatef(1, 2, 1, 0);
        SDL_Delay(16);
        SDL_GL_SwapWindow(window);
    }
    
}

void close()
{
    SDL_DestroyWindow(window);
    window = nullptr;
}

void drawRedTriangle()
{
    glColor3f(1,0,0);
    glVertexPointer(3, GL_FLOAT, 0, &redTriangle);
    glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
}
void drawGreenTriangle()
{
    glColor3f(0,1,0);
    glVertexPointer(3, GL_FLOAT, 0, &greenTriangle);
    glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
}
int main(int argc, char *argv[])
{
    if(!init(800,600))
    {
        close();
        return 1;
    } 
    eventLoop();
    close();
    return 0;
}
