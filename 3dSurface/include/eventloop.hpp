#ifndef EVENT_LOOP_HPP
#define EVENT_LOOP_HPP

#include <SDL2/SDL.h>

class EventLoop
{
private:
    SDL_Event ev;
public:
    bool KeyEventHandler(SDL_Event &event);
    void start(bool &runState);
};

#endif