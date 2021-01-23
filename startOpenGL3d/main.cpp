#include <SDL2/SDL.h>
#include <GL/gl.h>

SDL_Window *window = nullptr;

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
    SDL_GL_SwapWindow(window);
    SDL_Delay(3000);
}
void close()
{
    SDL_DestroyWindow(window);
    window = nullptr;
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
