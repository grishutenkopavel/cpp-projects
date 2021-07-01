#pragma once

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <functional>
#include <cstdlib>
#include <ctime>

#include <stdio.h>

typedef struct{
    int mapW;
    int mapH;
}  MapSize;

typedef struct {
    bool mine;
    bool flag;
    bool open;
    int cntAround;
} TCell;

class PlayGround
{
private:
    TCell** map;
    MapSize mapSize;
    int mines;
    int closedCell;

private:
    void showMine();
    void showField();
    void showFieldOpen();
    void showCount( int a );
    bool isCellInMap( int x, int y );
public:
    PlayGround( int mapH, int mapW );
    void render();
    void reactToAnEvent( SDL_Event* event );
    void genNewField();
    ~PlayGround();
};

