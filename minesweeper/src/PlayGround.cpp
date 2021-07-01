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

void PlayGround::showCount( int a ){
    
    std::function<void(float, float, float, float)> line;
    line = [](float x1, float y1, float x2, float y2) -> void
        {
            glVertex2f( x1, y1 );
            glVertex2f( x2, y2 );
        };
    glLineWidth( 3 );
    glColor3f( 1.f, 1.f, 0.f );
    glBegin(GL_LINES);
        if ( ( a != 1 ) && ( a != 4 ) ) line( 0.3f, 0.85f, 0.7f, 0.85f );
        if ( ( a != 0 ) && ( a != 1 ) && ( a != 7 ) ) line( 0.3f, 0.5f, 0.7f, 0.5f ); 
        if ( ( a != 1 ) && ( a != 4 ) && ( a != 7 ) ) line( 0.3f, 0.15f, 0.7f, 0.15f );
        
        if ( ( a != 5 ) && ( a != 6 ) ) line( 0.7f, 0.5f, 0.7f, 0.85f ); 
        if ( ( a != 2 ) ) line( 0.7f, 0.5f, 0.7f, 0.15f ); 
        if ( ( a != 1 ) && ( a != 2 ) && ( a != 3 ) && ( a != 7 ) ) line( 0.3f, 0.5f, 0.3f, 0.85f ); 
        if ( ( a == 0 ) || ( a == 2 ) || ( a == 6 ) || ( a == 8 ) ) line( 0.3f, 0.5f, 0.3f, 0.15f ); 
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
            showCount(i);
            glPopMatrix();
        }
    
}

bool PlayGround::isCellInMap( int x, int y ){
    return (x >= 0) && (y >= 0) && (x < mapSize.mapW) && (y < mapSize.mapH); 
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
        else {
            map[x][y].mine = true;

            for ( int dx = -1; dx < 2; dx++ )
                for ( int dy = -1; dy < 2; dy++ )
                    if ( isCellInMap( x+dx, y+dy ) )
                        map[x+dx][y+dy].cntAround += 1;
        }
    } 
}