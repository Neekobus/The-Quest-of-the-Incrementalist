#ifndef ACTORH
#define ACTORH

#include <string>

class Actor {    
    public:
        Actor();
        int x;
        int y;
        int width;
        int height;

        int velocity; //in pixels per second
        int maxVelocity;
        float acceleration;

        std::string name;

        void move(float elapsedMs);
};
#endif