#include "headers/Game.hpp"

int main( int argc, char* argw[] ){
    Game* minesweeper = new Game( 10, 10 );
    return minesweeper->start();
}