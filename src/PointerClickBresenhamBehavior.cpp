#include "PointerClickBresenhamBehavior.h"
#include <iostream>


PointerClickBresenhamBehavior::PointerClickBresenhamBehavior(Actor * actor){
    
    this->actor = actor;
    this->currentVelocity = Vector();
    this->maxVelocity = Vector();
    this->acceleration = Vector();

    this->destination = Vector();

    this->active = false;
    this->currentPath=std::vector<Vector>();
    
}

void PointerClickBresenhamBehavior::move(float elapsedMs) {

    if (this->inputManager->isPressed(InputManager::INPUT_POINTER_MAIN_BUTTON)) {
        this->active = true;
        this->destination.x = this->inputManager->pointer.x - (this->actor->width / 2);
        this->destination.y = this->inputManager->pointer.y - (this->actor->height / 2);

        std::cout << "Destination : x:" << this->destination.x << "/ y:" << this->destination.y << std::endl;

        this->currentPath = this->calculateSegment();
        this->currentPosition = 0;

        if (this->currentVelocity.x < this->startVelocity.x) {
            this->currentVelocity.x = this->startVelocity.x;    
        }
        

        std::cout << "New PATH !" << std::endl;


    } else {

        //this->currentVelocity.x = 0;
        //this->currentVelocity.y = 0;

        //return;
    }

    if (! this->active) {
        return;
    }

    if (this->currentPath.size() == 0) {
        return;
    }

    float elapsedSec = elapsedMs / 1000;
    float move = this->currentVelocity.x * elapsedSec ;

    currentVelocity.x *= this->acceleration.x;

    //bounds
    if (currentVelocity.x < startVelocity.x) {
        currentVelocity.x = 0;
    }

    if (currentVelocity.x > maxVelocity.x) {
        currentVelocity.x = maxVelocity.x;
    }

    this->currentPosition += move;

    std::cout << "Moving along PATH : " << move << std::endl;

    int max = this->currentPath.size();

    if (this->currentPosition >= max) {
        this->currentPosition = 0;
        
        this->actor->position.x = this->currentPath[max-1].x;
        this->actor->position.y = this->currentPath[max-1].y;
        this->currentVelocity.x = this->startVelocity.x;
        this->currentPath.clear();

        std::cout << "Finishing Path" << std::endl;
    } else {
        this->actor->position.x = this->currentPath[this->currentPosition].x;
        this->actor->position.y = this->currentPath[this->currentPosition].y;
   

    }

    



}

std::vector<Vector> PointerClickBresenhamBehavior::calculateSegment() {
    std::cout << "BRESENHAM segment..." << std::endl;

    int startCol = this->actor->position.x;
    int startRow = this->actor->position.y;

    int endCol = this->destination.x;
    int endRow = this->destination.y;

    int nextCol = startCol;
    int nextRow = startRow;

    int currentStep = 0;
    int fraction = 0;

    int deltaCol = endCol - startCol;
    int deltaRow = endRow - startRow;
    
    int stepCol;
    int stepRow;

    if (deltaCol < 0) stepCol = -1; else stepCol = 1;
    if (deltaRow < 0) stepRow = -1; else stepRow = 1;

    std::cout << "DeltaCol : " << deltaCol << std::endl;
    std::cout << "DeltaRow : " << deltaRow << std::endl;

    deltaCol = abs(deltaCol * 2);
    deltaRow = abs(deltaRow * 2);

    std::cout << "DeltaCol : " << deltaCol << std::endl;
    std::cout << "DeltaRow : " << deltaRow << std::endl;


    std::vector<Vector> path = std::vector<Vector>();
    
    //step 0
    Vector p;
    p.y = nextRow;
    p.x = nextCol;
    path.push_back(p);
    currentStep ++;

    std::cout << "First step row : " << p.y << std::endl;
    std::cout << "First step col : " << p.x << std::endl;

    //
    if (deltaCol > deltaRow) {

        fraction = deltaRow *2 - deltaCol;
        
        while (nextCol != endCol){
            if (fraction >= 0) {
                nextRow = nextRow + stepRow;
                fraction = fraction - deltaCol;
            }

            nextCol = nextCol + stepCol;
            fraction = fraction + deltaRow;

            Vector step;
            step.y = nextRow;
            step.x = nextCol;
            path.push_back(step);
            currentStep ++;

            std::cout << "Step " << currentStep << " row : " << step.y << std::endl;
            std::cout << "Step " << currentStep << " col : " << step.x << std::endl << std::endl;

        }


    } else {
        fraction = deltaCol *2 - deltaRow;
        
        while (nextRow != endRow){
            if (fraction >= 0) {
                nextCol = nextCol + stepCol;
                fraction = fraction - deltaRow;
            }

            nextRow = nextRow + stepRow;
            fraction = fraction + deltaCol;

            Vector step;
            step.x = nextCol;
            step.y = nextRow;
            path.push_back(step);
            currentStep ++;

            std::cout << "Step " << currentStep << " Col : " << step.x << std::endl;
            std::cout << "Step " << currentStep << " Row : " << step.y << std::endl << std::endl;

        }

    }


    std::cout << "...Done testing BRESENHAM." << std::endl;
    return path;

}
