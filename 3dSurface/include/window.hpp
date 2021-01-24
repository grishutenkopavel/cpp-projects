#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include "eventloop.hpp"

class Window
{
private:
    int width_;
    int height_;
    SDL_GLContext context;
    EventLoop el;
public:
    bool status;
    Window(int width, int height);
    void show();
    ~Window();

};

#endif
