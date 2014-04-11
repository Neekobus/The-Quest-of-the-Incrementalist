#ifndef ACTORH
#define ACTORH

#include <string>
#include "InputManager.h"

class Actor {  
    protected: 
        void checkMove(bool move); 
        int way;
    public:
        Actor();
        int x;
        int y;
        int width;
        int height;

        int currentVelocity; //in pixels per second
        int startVelocity;
        int maxVelocity;
        float acceleration;

        InputManager * inputManager;

        std::string name;

        void move(float elapsedMs);
};
#endif