#ifndef GAME_HPP
#define GAME_HPP
#include "eventloop.hpp"
#include "render.hpp"
class Game{
    private:
        EventLoop gLoop;
        Render renderer;
    public:
        void start(SDL_Window *window);
};
#endif