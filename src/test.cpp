#include <SDL2/SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{

	std::cout << "Testing SDL2..." << std::endl;

    SDL_Window * window = NULL;
    SDL_Surface * screenSurface = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        std::cerr << "SDL init fail. SDL_Error : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    } 

    window = SDL_CreateWindow( "INCREMENTALIST step 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
    
    if( window == NULL ) {
        std::cerr << "SDL CreateWindow fail. SDL_Error : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

	screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface with color
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );        
    SDL_UpdateWindowSurface( window );

    SDL_Delay( 2000 );
    
    SDL_DestroyWindow( window );
    SDL_Quit();

    std::cout << "...Done testing SDL2." << std::endl;

    return 0;
}