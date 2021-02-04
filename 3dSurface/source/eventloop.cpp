#include "../include/eventloop.hpp"

bool EventLoop::handleKeyEvent(SDL_Event &event)
{
    switch (event.key.keysym.sym)
    {
        case SDLK_ESCAPE:
            return false;
            break;
        
        case SDLK_UP:
            scene->getCamera()->rotateCameraVertical(5);
            break;
        case SDLK_DOWN:
            scene->getCamera()->rotateCameraVertical(-5);
            break;

        case SDLK_RIGHT:
            scene->getCamera()->rotateCameraHorizontal(-10);
            break;
        case SDLK_LEFT:
            scene->getCamera()->rotateCameraHorizontal(10);
            break;

        default:
            break;
    }
    return true;
}

void EventLoop::start(bool &runState)
{
    while (SDL_PollEvent(&ev) != 0)
    {
        if(ev.type == SDL_QUIT)
            runState = false;
        if(ev.type == SDL_KEYDOWN)
            runState = handleKeyEvent(ev);
    }
}

void EventLoop::setScene(Scene *scene)
{
    this->scene = scene;
}