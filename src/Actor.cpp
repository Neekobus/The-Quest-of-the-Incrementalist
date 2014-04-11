#include "Actor.h"
#include <iostream>

Actor::Actor(){
    this->position = Vector();
    this->width = 0;
    this->height = 0;
    
    this->currentVelocity = Vector();
    this->maxVelocity = Vector();
    this->acceleration = Vector();
    
    this->name = "unknown";
}

void Actor::checkMove(bool move){
    
    if (this->currentVelocity.x == 0 && ! move ) {
        return;
    }

    if (this->currentVelocity.x == 0 && move) {
        this->currentVelocity.x = this->startVelocity.x;
        this->acceleration.x = 1.3;
        return;
    }

    if (this->currentVelocity.x != 0 && !move) {
        this->acceleration.x = 0.8;
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
        this->currentVelocity.x = 0;
    }

    std::cout << "Acceleration : " << this->acceleration.x << "" << std::endl;
    
    //acceleration
    this->currentVelocity.x *= this->acceleration.x;

    //bounds
    if (this->currentVelocity.x < this->startVelocity.x) {
        this->currentVelocity.x = 0;
        way = 1;
    }

    if (this->currentVelocity.x > this->maxVelocity.x) {
        this->currentVelocity.x = this->maxVelocity.x;
    }

    float elapsedSec = elapsedMs / 1000;
    float move = this->currentVelocity.x * elapsedSec ;

    move *= this->way;    
    
    

    std::cout << "Velocity : " << this->currentVelocity.x << " px/s" << std::endl;
    std::cout << "Elapsed : " << elapsedSec << " s" << std::endl;
    std::cout << "Move : " << move << " px" << std::endl;
 
    this->position.x = this->position.x + move;
}
