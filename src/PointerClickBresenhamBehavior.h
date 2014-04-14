#ifndef POINTERCLICKBRESENHAMBEHAVIORH
#define POINTERCLICKBRESENHAMBEHAVIORH

#include "MoveBehavior.h"
#include <string>
#include "InputManager.h"
#include "Vector.h"
#include "Actor.h"
#include <vector>

class PointerClickBresenhamBehavior : public MoveBehavior {  
    protected: 
        bool active;
        Vector destination;

        std::vector<Vector> currentPath;
        int currentPosition;

        std::vector<Vector> calculateSegment();

    public:
        PointerClickBresenhamBehavior(Actor * actor);
        ~PointerClickBresenhamBehavior();

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