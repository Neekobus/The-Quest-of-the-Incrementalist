#ifndef NDSRENDERERH
#define NDSRENDERERH

#include <iostream>
#include <string>

#include "Actor.h"
#include "InputManager.h"

class NdsRenderer {    
    protected:
        std::string windowTitle;
        void screenColor(int color);
    public:
        InputManager * inputManager;

        NdsRenderer(std::string winTitle);
        void start();
        void stop();
        void showActor(Actor * actor);
        bool processEventsAndWaitForExit();
};
#endif