#ifndef ACTORH
#define ACTORH

#include <string>
#include "InputManager.h"
#include "Vector.h"

class Actor {  
    protected: 
        void checkMove(bool moveWay1, bool moveWay2, float &currentVelocity, float &startVelocity, float &acceleration, float &way);
        void doMove(float elapsedMs, float &acceleration, float &currentVelocity, float &startVelocity, float &maxVelocity, float &position, float &way);
        Vector way;
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