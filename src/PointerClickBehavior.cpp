#include "PointerClickBehavior.h"
#include <iostream>

PointerClickBehavior::PointerClickBehavior(Actor * actor){
    
    this->actor = actor;
    this->currentVelocity = Vector();
    this->maxVelocity = Vector();
    this->acceleration = Vector();

    this->destination = Vector();
    
}

void PointerClickBehavior::checkMove(bool moveWay1, bool moveWay2, float &currentVelocity, float &startVelocity, float &acceleration, float &way){
    
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

void PointerClickBehavior::doMove(float elapsedMs, float &acceleration, float &currentVelocity, float &startVelocity, float &maxVelocity, float &position, float &way, float &maxMove) {

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

    if (move > maxMove) {
        move = maxMove;
    }

    move *= way;    
    
    std::cout << "Velocity : " << currentVelocity << " px/s" << std::endl;
    std::cout << "Elapsed : " << elapsedSec << " s" << std::endl;
    std::cout << "Move : " << move << " px" << std::endl;
 
    position = position + move;
}

void PointerClickBehavior::move(float elapsedMs) {

    if (this->inputManager->isPressed(InputManager::INPUT_POINTER_MAIN_BUTTON)) {
        this->destination.x = this->inputManager->pointer.x;
        this->destination.y = this->inputManager->pointer.y;

        std::cout << "Destination : x:" << this->destination.x << "/ y:" << this->destination.y << std::endl;
    } else {
        return;
    }

    bool left, right, up, down = false;

    if (this->destination.x > this->actor->position.x) {
        right = true;
    } else if (this->destination.x < this->actor->position.x) {
        left = true;
    } 

    if (this->destination.y > this->actor->position.y) {
        down = true;
    } else if (this->destination.y < this->actor->position.y) {
        up = true;
    } 

    
    this->checkMove(left, right, this->currentVelocity.x, this->startVelocity.x, this->acceleration.x, this->way.x);
    this->checkMove(up,   down,  this->currentVelocity.y, this->startVelocity.y, this->acceleration.y, this->way.y);

    float maxMoveX = abs(this->destination.x - this->actor->position.x);
    float maxMoveY = abs(this->destination.y - this->actor->position.y);

    this->doMove(elapsedMs, this->acceleration.x, this->currentVelocity.x, this->startVelocity.x, this->maxVelocity.x, this->actor->position.x, this->way.x, maxMoveX);
    this->doMove(elapsedMs, this->acceleration.y, this->currentVelocity.y, this->startVelocity.y, this->maxVelocity.y, this->actor->position.y, this->way.y, maxMoveY);

}
