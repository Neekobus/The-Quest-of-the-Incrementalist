#ifndef ACTORH
#define ACTORH

#include <string>
#include "InputManager.h"
#include "Vector.h"

class Actor {  
    protected: 
        void checkMove(bool move); 
        int way;
    public:
        Actor();
        Vector position;

        int width;
        int height;

        Vector currentVelocity;
        Vector startVelocity;
        Vector maxVelocity;
        Vector acceleration;

        InputManager * inputManager;

        std::string name;

        void move(float elapsedMs);
};
#endif