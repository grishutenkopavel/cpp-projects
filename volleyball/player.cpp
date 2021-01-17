#include <SDL2/SDL.h>
#include "include/player.hpp"

Player::Player(float x, float y, float dx, float dy, float r)
    : Ball(x, y, dx, dy, r)
    {
        this->gravity = 0.004;
    }

void Player::playerMove(float wl1, float wl2)
{
    static float speed = 0.05;
    if (this->isLeft) x -= speed;
    else if (this->isRight) x += speed;

    if(x - r < wl1) x = wl1 + r;
    if(x + r > wl2) x = wl2 - r;

    if( this->isJump && (y < -0.99 + r))
        dy = speed * 1.4;
    y += dy;
    dy -= gravity;

    if(y - r < -1)
    {
        y = -1 + r;
        dy = 0;
    }
}