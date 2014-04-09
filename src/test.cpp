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

    window = SDL_CreateWindow( "INCREMENTALIST step 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
    
    if( window == NULL ) {
        std::cerr << "SDL CreateWindow fail. SDL_Error : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

	screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface with color
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );        
    SDL_UpdateWindowSurface( window );

    //event loop
    SDL_Event e;
    bool running = true;

    while(running) {

    	if (SDL_PollEvent( &e ) == 0) {
    		continue;
    	}
    	
    	std::cout << "Event fired : " << e.type << std::endl;

        if( e.type == SDL_QUIT ) {
        	running = false;
        	std::cout << "Event was QUIT : will quit." << std::endl;
        }

    }

    
    SDL_DestroyWindow( window );
    SDL_Quit();

    std::cout << "...Done testing SDL2." << std::endl;

    return 0;
}