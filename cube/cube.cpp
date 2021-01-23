#include <SDL2/SDL.h>
#include <GL/gl.h>

SDL_Window *window = nullptr;

float cubeVertex[] = {
    -0.5, 0.5, 0.5, //0
    -0.5, -0.5, 0.5, //1
    0.5, -0.5, 0.5, //2
    0.5, 0.5, 0.5, //3
    -0.5, 0.5, -0.5, //4
    -0.5, -0.5, -0.5, //5
    0.5, -0.5, -0.5,//6
    0.5, 0.5, -0.5//7

};

float cubeColor[] = {
    1,0,0,
    0,1,0,
    0,0,1,
    1,1,0,
    1,0,0,
    0,1,0,
    0,0,1,
    1,1,0
};

GLuint cube[] = {
    0,1,2,3,
    1,5,6,2,
    0,1,5,4,
    2,3,7,6,
    0,3,7,4,
    4,5,6,7
};

bool init(int witdh, int height);
void eventLoop();
void close();

void drawCube();

bool init(int witdh, int height)
{
    SDL_GLContext context;
    bool success = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return !success;
    }
    window = SDL_CreateWindow("Cube",
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
    glEnable(GL_DEPTH_TEST);
    return success;
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
        drawCube();
        glRotatef(2, 2, 1, -0.5);
        SDL_Delay(16);
        SDL_GL_SwapWindow(window);
    }
    
}

void close()
{
    SDL_DestroyWindow(window);
    window = nullptr;
}

void drawCube()
{
    glVertexPointer(3, GL_FLOAT, 0, &cubeVertex);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, &cubeColor);
    glEnableClientState(GL_COLOR_ARRAY);
        glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, &cube);
    glDisableClientState(GL_COLOR_ARRAY);
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
