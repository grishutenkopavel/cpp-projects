#ifndef GAME_HPP
#define GAME_HPP
#include "eventloop.hpp"
#include "render.hpp"

class Game{
    // private:
    //     Render render;
    EventLoop gLoop;
    public:
        void start(SDL_Window *window);
};
#endif