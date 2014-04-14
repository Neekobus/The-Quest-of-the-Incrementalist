#ifndef KEYBOARDBEHAVIORH
#define KEYBOARDBEHAVIORH

#include "MoveBehavior.h"
#include <string>
#include "InputManager.h"
#include "Vector.h"
#include "Actor.h"

class KeyboardBehavior : public MoveBehavior {  
    protected: 
        void checkMove(bool moveWay1, bool moveWay2, float &currentVelocity, float &startVelocity, float &acceleration, float &way);
        void doMove(float elapsedMs, float &acceleration, float &currentVelocity, float &startVelocity, float &maxVelocity, float &position, float &way);
    public:
        KeyboardBehavior(Actor * actor);
        ~KeyboardBehavior();

        Actor * actor;

        Vector way;
        Vector currentVelocity;
        Vector startVelocity;
        Vector maxVelocity;
        Vector acceleration;

        InputManager * inputManager;

        virtual void move(float elapsedMs);
};
#endif