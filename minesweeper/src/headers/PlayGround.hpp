#pragma once

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <functional>
#include <cstdlib>
#include <ctime>

#include "structures.h"

class PlayGround
{
private:
    WindowSize windowSize;
    TCell** map;
    MapSize mapSize;
    int mines;
    int closedCell;
    bool failed;
    int winCount;
private:
    void showMine();
    void showField();
    void showFieldOpen();
    void showFlag();
    void showCount( int a );
    void openField( int x, int y );
    void screenToOpenGL( SDL_Event* event, float* ox, float* oy );
    bool isCellInMap( int x, int y );

public:
    PlayGround( WindowSize winSize, int mapH, int mapW );
    void render();
    void reactToAnEvent( SDL_Event* event );
    void genNewField();
    ~PlayGround();
};

