#include <iostream>
#include "Actor.h"

Actor::Actor(){
    this->position = Vector();
    this->width = 0;
    this->height = 0;
    
    this->behavior = NULL;
    this->name = "unknown";
}

void Actor::move(float elapsedMs) {
    this->behavior->move(elapsedMs);
}
