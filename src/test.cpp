#include <SDL2/SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{

	std::cout << "Testing SDL2..." << std::endl;

    SDL_Window * window = NULL;
    SDL_Surface * screenSurface = NULL;
    SDL_Surface * heroImage = NULL;

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

	heroImage = SDL_LoadBMP( "hero.bmp" );

    if( heroImage == NULL ) {
    	std::cerr << "SDL LoadBMP fail. SDL_Error : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow( window );
    	SDL_Quit();
        return 1;
    }

    SDL_Rect destRect;
	destRect.x = (WINDOW_WIDTH/2) - 100/2;
	destRect.y = (WINDOW_HEIGHT/2) - 158/2;
	destRect.w = 100;
	destRect.h = 158;
    
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xAA, 0xAA, 0xAA ) );
    SDL_BlitSurface( heroImage, NULL, screenSurface, &destRect );
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

    SDL_FreeSurface( heroImage );
    SDL_DestroyWindow( window );
    SDL_Quit();

    std::cout << "...Done testing SDL2." << std::endl;

    return 0;
}