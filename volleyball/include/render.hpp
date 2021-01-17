#ifndef RENDER_HPP
#define RENDER_HPP
#include <SDL2/SDL.h>
#include "ball.hpp"
#include "player.hpp"
class Render
{
    private:
        void drawCube(float x, float y, float dx, float dy);
        void renderBackground();
        void renderGrid();
    public:
        void show(SDL_Window *window, Ball *ball, Player *player1, Player *player2);
};

#endif