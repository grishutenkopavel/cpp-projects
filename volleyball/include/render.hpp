#ifndef RENDER_HPP
#define RENDER_HPP
#include <SDL2/SDL.h>
#include "ball.hpp"

class Render
{
    private:
        Ball ball = Ball(0, 0.5, 0.15, -0.01, 0.2);
        void drawCube(float x, float y, float dx, float dy);
        void renderBackground();
        void renderGrid();
    public:
        void show(SDL_Window *window);
};

#endif