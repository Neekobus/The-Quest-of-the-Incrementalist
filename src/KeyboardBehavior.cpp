#include "KeyboardBehavior.h"
#include <iostream>

KeyboardBehavior::KeyboardBehavior(Actor * actor){
    
    this->actor = actor;
    this->currentVelocity = Vector();
    this->maxVelocity = Vector();
    this->acceleration = Vector();
    
}

void KeyboardBehavior::checkMove(bool moveWay1, bool moveWay2, float &currentVelocity, float &startVelocity, float &acceleration, float &way){
    
    bool move = moveWay1 || moveWay2; 

    if (currentVelocity == 0 && ! move ) {
        return;
    }

    if (currentVelocity == 0 && move) {
        currentVelocity = startVelocity;
        acceleration = 1.3;
        return;
    }

    if (currentVelocity != 0 && !move) {
        acceleration = 0.8;
        return;
    }


    if (moveWay1) {
        way = -1; 
    }

    if (moveWay2) {
        way = 1; 
    }

    if (moveWay1 && moveWay2) {
        currentVelocity = 0;
    }

}

void KeyboardBehavior::doMove(float elapsedMs, float &acceleration, float &currentVelocity, float &startVelocity, float &maxVelocity, float &position, float &way) {

    std::cout << "Acceleration : " << acceleration << "" << std::endl;
    
    //acceleration
    currentVelocity *= acceleration;

    //bounds
    if (currentVelocity < startVelocity) {
        currentVelocity = 0;
        way = 1;
    }

    if (currentVelocity > maxVelocity) {
        currentVelocity = maxVelocity;
    }

    float elapsedSec = elapsedMs / 1000;
    float move = currentVelocity * elapsedSec ;

    move *= way;    
    
    std::cout << "Velocity : " << currentVelocity << " px/s" << std::endl;
    std::cout << "Elapsed : " << elapsedSec << " s" << std::endl;
    std::cout << "Move : " << move << " px" << std::endl;
 
    position = position + move;
}

void KeyboardBehavior::move(float elapsedMs) {
    bool right  = this->inputManager->isPressed(InputManager::INPUT_RIGHT_ARROW);
    bool left   = this->inputManager->isPressed(InputManager::INPUT_LEFT_ARROW);
    bool up     = this->inputManager->isPressed(InputManager::INPUT_UP_ARROW);
    bool down   = this->inputManager->isPressed(InputManager::INPUT_DOWN_ARROW);
    
    this->checkMove(left, right, this->currentVelocity.x, this->startVelocity.x, this->acceleration.x, this->way.x);
    this->checkMove(up,   down,  this->currentVelocity.y, this->startVelocity.y, this->acceleration.y, this->way.y);

    this->doMove(elapsedMs, this->acceleration.x, this->currentVelocity.x, this->startVelocity.x, this->maxVelocity.x, this->actor->position.x, this->way.x);
    this->doMove(elapsedMs, this->acceleration.y, this->currentVelocity.y, this->startVelocity.y, this->maxVelocity.y, this->actor->position.y, this->way.y);
}
