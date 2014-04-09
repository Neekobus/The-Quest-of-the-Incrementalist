#ifndef SDL2RENDERERH
#define SDL2RENDERERH

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <iostream>
#include <string>

#include "Actor.h"

class Sdl2Renderer {    
    protected:
        int windowHeight;
        int windowWidth;
        std::string windowTitle;

        SDL_Window * window;
        SDL_Surface * screen;

    public:
        Sdl2Renderer(std::string winTitle, int winWidth, int winHeight);
        void start();
        void stop();
        void showActor(Actor * actor);
        bool waitForExit();
};
#endif