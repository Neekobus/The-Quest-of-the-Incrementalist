#ifndef MAINCONTROLLERH
#define MAINCONTROLLERH

#include "Actor.h"
#include "Sdl2Renderer.h"

class MainController { 
	protected: 
		bool running;   
    public:
        MainController();
        ~MainController();
        Sdl2Renderer * renderer;
        Actor * actor;

        void run();
        void step(float elapsedTime);
};
#endif