#ifndef ACTORH
#define ACTORH

#include <string>
#include "InputManager.h"
#include "Vector.h"

class PointerClickBehavior;
class Actor {  
    public:
        Actor();
        Vector position;

        int width;
        int height;

        PointerClickBehavior * behavior;
        
        std::string name;

        void move(float elapsedMs);
};
#endif