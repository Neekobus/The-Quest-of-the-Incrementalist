#ifndef ACTORH
#define ACTORH

#include <string>
#include "InputManager.h"
#include "Vector.h"

class KeyboardBehavior;
class Actor {  
    public:
        Actor();
        Vector position;

        int width;
        int height;

        KeyboardBehavior * behavior;
        
        std::string name;

        void move(float elapsedMs);
};
#endif