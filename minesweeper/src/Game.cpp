#include "headers/Game.hpp"

Game::Game(/* args */)
: size({ 640, 480 })
{
    errorStatus = init();
    
}

Game::~Game()
{
}

int Game::init (){
    
    SDL_Init( SDL_INIT_EVERYTHING );

    window = SDL_CreateWindow( "window", SDL_WINDOWPOS_CENTERED, 
                            SDL_WINDOWPOS_CENTERED,
                            size.width,
                            size.height,
                            SDL_WINDOW_SHOWN );
    if( window == nullptr ){
        return -1;
    }

    return 0;
}

void Game::eventLoop(){

    bool running = true;
    SDL_Event event;

    while(running){
        while( SDL_PollEvent( &event ) != 0 ){
            if(event.type == SDL_QUIT){
                running = false;
            }
            if( event.type == SDL_KEYDOWN ){
                switch ( event.key.keysym.sym )
                {
                case SDLK_q:
                    running = false;
                    break;
                
                default:
                    break;
                }
            }
        }
    }
}


int Game::start(){
    if ( errorStatus == 0 ){
        SDL_ShowWindow( this->window );
        eventLoop();
        return 0;
    } else return errorStatus;
}