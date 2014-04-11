#include "Actor.h"
#include <iostream>

Actor::Actor(){
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->currentVelocity = 0;
    this->maxVelocity = 0;
    this->acceleration = 0;
    this->name = "unknown";
}

void Actor::checkMove(bool move){
    
    if (this->currentVelocity == 0 && ! move ) {
        return;
    }

    if (this->currentVelocity == 0 && move) {
        this->currentVelocity = this->startVelocity;
        this->acceleration = 1.3;
        return;
    }

    if (this->currentVelocity != 0 && !move) {
        this->acceleration = 0.8;
        return;
    }

}


void Actor::move(float elapsedMs) {
    bool right = this->inputManager->isPressed(InputManager::INPUT_RIGHT_ARROW);
    bool left = this->inputManager->isPressed(InputManager::INPUT_LEFT_ARROW);
    
    this->checkMove(right || left);    
    
    if (left) {
        way = -1; 
    }

    if (right) {
        way = 1; 
    }

    if (left && right) {
        this->currentVelocity = 0;
    }

    std::cout << "Acceleration : " << this->acceleration << "" << std::endl;
    
    //acceleration
    this->currentVelocity *= this->acceleration;

    //bounds
    if (this->currentVelocity < this->startVelocity) {
        this->currentVelocity = 0;
        way = 1;
    }

    if (this->currentVelocity > this->maxVelocity) {
        this->currentVelocity = this->maxVelocity;
    }

    float elapsedSec = elapsedMs / 1000;
    float move = this->currentVelocity * elapsedSec ;

    move *= this->way;    
    
    

    std::cout << "Velocity : " << this->currentVelocity << " px/s" << std::endl;
    std::cout << "Elapsed : " << elapsedSec << " s" << std::endl;
    std::cout << "Move : " << move << " px" << std::endl;
 
    this->x = this->x + move;
}
