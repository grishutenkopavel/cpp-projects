#ifndef EVENT_LOOP_HPP
#define EVENT_LOOP_HPP
#include <SDL2/SDL.h>
class EventLoop{
        SDL_Event ev;
    public:
        bool loop();
};
#endif