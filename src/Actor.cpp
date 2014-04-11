#include "Actor.h"
#include <iostream>

Actor::Actor(){
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->velocity = 0;
    this->maxVelocity = 0;
    this->acceleration = 0;
    this->name = "unknown";
}


void Actor::move(float elapsedMs) {
    //acceleration
    this->velocity *= this->acceleration;

    if (this->velocity > this->maxVelocity) {
        this->velocity = this->maxVelocity;
    }

    float elapsedSec = elapsedMs / 1000;
    float move = this->velocity * elapsedSec;

    //std::cout << "Velocity : " << this->velocity << " px/s" << std::endl;
    //std::cout << "Elapsed : " << elapsedSec << " s" << std::endl;
    //std::cout << "Move : " << move << " px" << std::endl;
 
    this->x = this->x + move;
}
