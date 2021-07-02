#include "headers/Game.hpp"

Game::Game( int cellsVertically, int cellsHorizontally )
: size({ 500, 500 })
{
    errorStatus = init();
    gameField = new PlayGround( size, cellsVertically, cellsHorizontally );
}

Game::~Game()
{
    delete gameField;
}

int Game::init (){
    
    SDL_GLContext context;
    SDL_Init( SDL_INIT_EVERYTHING );

    window = SDL_CreateWindow( "Minesweeper", SDL_WINDOWPOS_CENTERED, 
                            SDL_WINDOWPOS_CENTERED,
                            size.width,
                            size.height,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    
    context = SDL_GL_CreateContext(window);

    if( window == nullptr ){
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    return 0;
}

void Game::eventLoop(){

    bool running = true;
    SDL_Event event;

    while(running){
        while( SDL_PollEvent( &event ) != 0 ){
            //ex. handle moving or closing window
            reactToWindowEvent( &event, &running );
            //game event handler
            gameField->reactToAnEvent( &event );
        }
        glClear( GL_COLOR_BUFFER_BIT );
        gameField->render();
        SDL_GL_SwapWindow( window );
    }
}

void Game::reactToWindowEvent( SDL_Event* event, bool* programStatus ){
    if( event->type == SDL_QUIT ){
        *programStatus = false;
    }
    if( event->type == SDL_KEYDOWN ){
        switch ( event->key.keysym.sym )
        {
        case SDLK_q:
            *programStatus = false;
            break;
        
        default:
            break;
        }
    }
}
void Game::newGame(){
    gameField->genNewField();
}
int Game::start(){
    if ( errorStatus == 0 ){
        newGame();
        SDL_ShowWindow( this->window );
        eventLoop();
        return 0;
    } else return errorStatus;
}