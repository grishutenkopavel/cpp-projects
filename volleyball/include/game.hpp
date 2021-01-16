#ifndef GAME_HPP
#define GAME_HPP
#include "eventloop.hpp"

class Game{
    private:
        EventLoop gLoop;
        void drawCube(float x, float y, float dx, float dy);
        void renderBackground();
        void renderGrid();
    public:
        void start(SDL_Window *window);
};
#endif