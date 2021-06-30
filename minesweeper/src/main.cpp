#include "headers/Game.hpp"

int main( int argc, char* argw[] ){
    Game* minesweeper = new Game();
    return minesweeper->start();
}