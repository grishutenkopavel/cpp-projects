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

void PlayGround::reactToAnEvent( SDL_Event* event ){
    
}

void PlayGround::showMine(){
    glBegin( GL_TRIANGLE_FAN );
        glColor3f( 0.f, 0.f, 0.f );
        glVertex2f( 0.3f, 0.3f );
        glVertex2f( 0.7f, 0.3f );
        glVertex2f( 0.7f, 0.7f );
        glVertex2f( 0.3f, 0.7f );
    glEnd();
}
void PlayGround::showField(){
    glBegin( GL_TRIANGLE_STRIP );
        glColor3f( 0.8f, 0.8f, 0.8f ); glVertex2f( 0.f, 1.f );
        glColor3f( 0.7f, 0.7f, 0.7f ); glVertex2f( 1.f, 1.f ); glVertex2f( 0.f, 0.f );
        glColor3f( 0.6f, 0.6f, 0.6f ); glVertex2f( 1.f, 0.f );
    glEnd();
}
void PlayGround::render(){
    glLoadIdentity();
    glScalef( 2.f/mapSize.mapW, 2.f/mapSize.mapH,  1.f );
    glTranslatef( -mapSize.mapW*0.5f, -mapSize.mapH*0.5f, 0.f );

    for ( int j = 0; j < mapSize.mapH; j++ )
        for ( int i = 0; i < mapSize.mapW; i++ ){
            glPushMatrix();
            glTranslatef( i, j, 0 );
            showField();
            if ( map[i][j].mine )
                showMine();
            glPopMatrix();
        }
    
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