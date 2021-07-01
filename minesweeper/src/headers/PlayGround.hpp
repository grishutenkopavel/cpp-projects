#pragma once

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <cstdlib>
#include <ctime>

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
public:
    PlayGround( int mapH, int mapW );
    void render();
    void reactToAnEvent( SDL_Event* event );
    void genNewField();
    ~PlayGround();
};

