#ifndef EVENT_LOOP_HPP
#define EVENT_LOOP_HPP

#include <SDL2/SDL.h>
#include "camera.hpp"
#include "scene.hpp"
class EventLoop
{
private:
    Scene *scene;
    SDL_Event ev;
public:
    bool handleKeyEvent(SDL_Event &event);
    void start(bool &runState);
    void setScene(Scene *scene);
};

#endif