#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SDL2/SDL.h>
#include "ball.hpp"

class Player : public Ball
{
    public:
        Player(float x, float y, float dx, float dy, float r);
        void playerMove(SDL_KeyCode key, float wl1, float wl2); 
};
#endif