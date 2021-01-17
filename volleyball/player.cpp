#include <SDL2/SDL.h>
#include "include/player.hpp"

Player::Player(float x, float y, float dx, float dy, float r)
    : Ball(x, y, dx, dy, r)
    {
        this->gravity = 0.004;
    }

void Player::playerMove(SDL_KeyCode key, float wl1, float wl2)
{
    static float speed = 0.05;
    // if (GetKeyState(left) < 0) x -= speed;
    // else if (GetKeyState(right) < 0) x += speed;

    if(x - r < wl1) x = wl1 + r;
    if(x + r > wl2) x = wl1 - r;
} 