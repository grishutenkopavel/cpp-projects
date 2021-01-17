#ifndef EVENT_LOOP_HPP
#define EVENT_LOOP_HPP
#include <SDL2/SDL.h>
#include "player.hpp"
class EventLoop{
        SDL_Event ev;
    public:
        bool loop(Player *player1, Player *player2);
};
#endif