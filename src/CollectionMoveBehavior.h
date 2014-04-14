#ifndef COLLECTIONMOVEBEHAVIORH
#define COLLECTIONMOVEBEHAVIORH

#include "MoveBehavior.h"
#include <vector>

class CollectionMoveBehavior : public MoveBehavior {  
    public:
        CollectionMoveBehavior();
        ~CollectionMoveBehavior();

        std::vector<MoveBehavior*> behaviors;

        virtual void move(float elapsedMs);
};
#endif