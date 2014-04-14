#include <iostream>

#include "Actor.h"
//#include "Sdl2Renderer.h"
#include "InputManager.h"
#include "MainController.h"

#include "KeyboardBehavior.h"
#include "PointerClickBehavior.h"
#include "MoveBehavior.h"
#include "CollectionMoveBehavior.h"

#include "NdsRenderer.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

MoveBehavior * buildMoveBehavior(Actor* actor, InputManager * inputManager) {

    PointerClickBehavior * pointerBehavior = new PointerClickBehavior(actor);
    pointerBehavior->inputManager = inputManager;
    pointerBehavior->currentVelocity.x = 0;
    pointerBehavior->currentVelocity.y = 0;
    pointerBehavior->startVelocity.x = 100;
    pointerBehavior->startVelocity.y = 100;
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

	std::cout << "Testing NDS..." << std::endl;

    InputManager * inputManager = new InputManager();
    
    Actor * hero = new Actor();
    hero->name = "hero.png";

    hero->width = 20;
    hero->height = 30;
    hero->position.x = 0;
    hero->position.y = 0;
    hero->behavior = buildMoveBehavior(hero, inputManager);

    NdsRenderer * renderer = new NdsRenderer("Incrementalist step 4x");

    renderer->inputManager = inputManager;

    MainController * controller = new MainController();
    controller->actor = hero;
    controller->renderer = renderer;
    controller->run();
    
    delete renderer->inputManager;
    delete controller;
    delete hero;
    delete renderer;

    std::cout << "...Done testing NDS." << std::endl;

    return 0;
}