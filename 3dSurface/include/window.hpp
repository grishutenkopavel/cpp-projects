#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include "eventloop.hpp"
#include "renderer.hpp"
#include "object.hpp"
#include "camera.hpp"
class Window
{
private:
    int width_;
    int height_;
    SDL_GLContext context;
    EventLoop el;
    Renderer render;
    Camera camera;
public:
    bool status;
    Window(int width, int height);
    void show();
    void drawObject(Object &object);
    ~Window();
};

#endif
