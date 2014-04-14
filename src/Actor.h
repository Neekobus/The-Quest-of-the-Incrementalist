#ifndef ACTORH
#define ACTORH

#include <string>
#include "InputManager.h"
#include "Vector.h"
#include "MoveBehavior.h"

class Actor {  
    public:
        Actor();
        Vector position;

        int width;
        int height;

        MoveBehavior * behavior;
        
        std::string name;

        void move(float elapsedMs);
};
#endif