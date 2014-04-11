#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <iostream>

#include "Actor.h"
#include "Sdl2Renderer.h"
#include "InputManager.h"
#include "MainController.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{

	std::cout << "Testing SDL2..." << std::endl;

    InputManager * inputManager = new InputManager();

    Actor * hero = new Actor();
    hero->name = "hero.png";
    hero->width = 100;
    hero->height = 158;
    //hero->x = (WINDOW_WIDTH/2) - hero->width/2;
    hero->y = (WINDOW_HEIGHT/2) - hero->height/2;
    
    hero->currentVelocity = 0;
    hero->startVelocity = 20;
    hero->maxVelocity = 300;
    hero->acceleration = 0;

    hero->inputManager = inputManager;

    Sdl2Renderer * renderer = new Sdl2Renderer("Incrementalist step 3", WINDOW_WIDTH, WINDOW_HEIGHT);
    renderer->inputManager = inputManager;


    MainController * controller = new MainController();
    controller->actor = hero;
    controller->renderer = renderer;
    controller->run();
    
    delete renderer->inputManager;
    delete controller;
    delete hero;
    delete renderer;

    std::cout << "...Done testing SDL2." << std::endl;

    return 0;
}