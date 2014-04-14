#ifndef POINTERCLICKBEHAVIORH
#define POINTERCLICKBEHAVIORH

#include "MoveBehavior.h"
#include <string>
#include "InputManager.h"
#include "Vector.h"
#include "Actor.h"

class PointerClickBehavior : public MoveBehavior {  
    protected: 
        bool active;
        Vector destination;

        void checkMove(bool moveWay1, bool moveWay2, float &currentVelocity, float &startVelocity, float &acceleration, float &way);
        void doMove(float elapsedMs, float &acceleration, float &currentVelocity, float &startVelocity, float &maxVelocity, float &position, float &way, float &maxMove);
    public:
        PointerClickBehavior(Actor * actor);
        ~PointerClickBehavior();

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