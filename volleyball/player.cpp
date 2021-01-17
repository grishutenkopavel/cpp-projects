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
    if (key == SDLK_LEFT || key == SDLK_a) x -= speed;
    else if (key == SDLK_RIGHT || key == SDLK_d) x += speed;

    if(x - r < wl1) x = wl1 + r;
    if(x + r > wl2) x = wl1 - r;
} 