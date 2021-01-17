#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SDL2/SDL.h>
#include "ball.hpp"

class Player : public Ball
{
    public:
        bool isJump = false;
        bool isRight;
        bool isLeft;
        Player(float x, float y, float dx, float dy, float r);
        void playerMove(float wl1, float wl2); 
};
#endif