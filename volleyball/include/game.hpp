#ifndef GAME_HPP
#define GAME_HPP
#include "eventloop.hpp"
#include "render.hpp"
#include "player.hpp"
#include "ball.hpp"

class Game{
    private:
        Ball ball = Ball(0, 0.5, 0.15, -0.01, 0.2);
        Player player1 = Player(-1, 0, 0, 0, 0.2);
        Player player2 = Player(1, 0, 0, 0, 0.2);

        EventLoop gLoop;
        Render renderer;
    public:
        void start(SDL_Window *window);
};
#endif