#include "headers/PlayGround.hpp"


PlayGround::PlayGround( int mapH, int mapW )
: mapSize({mapW, mapH})
{
    map = new TCell*[mapSize.mapH];
    for( int i = 0; i < mapSize.mapH; i++ ){
        map[i] = new TCell[mapSize.mapW];
    }
}

PlayGround::~PlayGround()
{
    //add delete map
}

void PlayGround::render(){
    //renderCell();
    //renderMap();
    glBegin( GL_TRIANGLE_FAN );
        glColor3f( 1.f, 0.f, 0.f );
        glVertex2f( 0.3f, 0.3f );
        glVertex2f( 0.7f, 0.3f );
        glVertex2f( 0.7f, 0.7f );
        glVertex2f( 0.3f, 0.7f );
    glEnd();
}
void PlayGround::reactToAnEvent( SDL_Event* event ){
    
}

void PlayGround::genNewField()
{
    srand(time(NULL));
    for ( int i = 0; i < mapSize.mapH; i++ )
        memset(map[i], 0, sizeof(map[i]));
    
    mines = 20;
    closedCell = mapSize.mapH * mapSize.mapW;

    for ( int i = 0; i < mines; i++ ){
        int x = rand() % mapSize.mapW;
        int y = rand() % mapSize.mapH;
        if ( map[x][y].mine )
            i--;
        else 
            map[x][y].mine = true;
    } 
}