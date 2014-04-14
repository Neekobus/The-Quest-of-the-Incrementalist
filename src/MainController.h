#ifndef MAINCONTROLLERH
#define MAINCONTROLLERH

#include "Actor.h"
#include "NdsRenderer.h"

class MainController { 
	protected: 
		bool running;   
    public:
        MainController();
        ~MainController();
        NdsRenderer * renderer;
        Actor * actor;

        void run();
        void step(float elapsedTime);
};
#endif