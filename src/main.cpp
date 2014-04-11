#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <iostream>

#include "Actor.h"
#include "Sdl2Renderer.h"
#include "MainController.h"

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
    hero->velocity = 10;
    hero->maxVelocity = 300;
    hero->acceleration = 1.2;
    
    Sdl2Renderer * renderer = new Sdl2Renderer("Incrementalist step 2", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    MainController * controller = new MainController();
    controller->actor = hero;
    controller->renderer = renderer;
    controller->run();
    
    delete controller;
    delete hero;
    delete renderer;

    std::cout << "...Done testing SDL2." << std::endl;

    return 0;
}