#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <iostream>

#include "Actor.h"
#include "Sdl2Renderer.h"
#include "InputManager.h"
#include "MainController.h"
#include "KeyboardBehavior.h"
#include "PointerClickBehavior.h"
#include "MoveBehavior.h"
#include "CollectionMoveBehavior.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

MoveBehavior * buildMoveBehavior(Actor* actor, InputManager * inputManager) {

    PointerClickBehavior * pointerBehavior = new PointerClickBehavior(actor);
    pointerBehavior->inputManager = inputManager;
    pointerBehavior->currentVelocity.x = 0;
    pointerBehavior->currentVelocity.y = 0;
    pointerBehavior->startVelocity.x = 20;
    pointerBehavior->startVelocity.y = 20;
    pointerBehavior->maxVelocity.x = 500;
    pointerBehavior->maxVelocity.y = 500;
    pointerBehavior->acceleration.x = 0;
    pointerBehavior->acceleration.y = 0;

    KeyboardBehavior * keyboardBehavior = new KeyboardBehavior(actor);
    keyboardBehavior->inputManager = inputManager;
    keyboardBehavior->currentVelocity.x = 0;
    keyboardBehavior->currentVelocity.y = 0;
    keyboardBehavior->startVelocity.x = 20;
    keyboardBehavior->startVelocity.y = 20;
    keyboardBehavior->maxVelocity.x = 300;
    keyboardBehavior->maxVelocity.y = 300;
    keyboardBehavior->acceleration.x = 0;
    keyboardBehavior->acceleration.y = 0;

    CollectionMoveBehavior * collection = new CollectionMoveBehavior();
    collection->behaviors.push_back(pointerBehavior);
    collection->behaviors.push_back(keyboardBehavior);

    return collection;
}

 
int main( int argc, char* args[] )
{

	std::cout << "Testing SDL2..." << std::endl;

    InputManager * inputManager = new InputManager();
    
    Actor * hero = new Actor();
    hero->name = "hero.png";
    hero->width = 100;
    hero->height = 158;
    hero->position.x = (WINDOW_WIDTH/2) - hero->width/2;
    hero->position.y = (WINDOW_HEIGHT/2) - hero->height/2;
    hero->behavior = buildMoveBehavior(hero, inputManager);

    Sdl2Renderer * renderer = new Sdl2Renderer("Incrementalist step 4", WINDOW_WIDTH, WINDOW_HEIGHT);
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