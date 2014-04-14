#include "CollectionMoveBehavior.h"
#include <iostream>

CollectionMoveBehavior::CollectionMoveBehavior(){
    this->behaviors = std::vector<MoveBehavior *>();
}

void CollectionMoveBehavior::move(float elapsedMs) {

    int count = this->behaviors.size();

    for(int i = 0; i < count; i++ ){
        this->behaviors[i]->move(elapsedMs);
    }
    
}
