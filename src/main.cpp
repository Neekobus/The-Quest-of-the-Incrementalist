#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <iostream>

#include "Actor.h"
#include "Sdl2Renderer.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{

	std::cout << "Testing SDL2..." << std::endl;

    Actor * hero = new Actor();
    hero->name = "hero.png";
    hero->width = 100;
    hero->height = 158;
    hero->x = 0;
    hero->y = (WINDOW_HEIGHT/2) - hero->height/2;
    
    Sdl2Renderer * renderer = new Sdl2Renderer("Incrementalist step 2", WINDOW_WIDTH, WINDOW_HEIGHT);
    renderer->start();

    bool running = true;
    while(running) {
        hero->x = hero->x + 1;

        renderer->showActor(hero);
        running = renderer->waitForExit(); 
    }
    
    renderer->stop();

    delete hero;
    delete renderer;

    std::cout << "...Done testing SDL2." << std::endl;

    return 0;
}