#ifndef MOVEBEHAVIORH
#define MOVEBEHAVIORH

class MoveBehavior {  
    public:
        virtual void move(float elapsedMs) = 0;
};
#endif