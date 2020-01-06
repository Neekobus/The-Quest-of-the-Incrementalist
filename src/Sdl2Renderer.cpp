
#include "Sdl2Renderer.h"

Sdl2Renderer::Sdl2Renderer(std::string winTitle, int winWidth, int winHeight){
    this->windowTitle = winTitle;
    this->windowHeight = winHeight;
    this->windowWidth = winWidth;
    this->window = NULL;
    this->screen = NULL;

    this->scale = 1;
}

void Sdl2Renderer::start(){
    std::cout << "Starting SDL2 Renderer..." << std::endl;


    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        std::cerr << "SDL init fail. SDL_Error : " << SDL_GetError() << std::endl;
        return this->stop();
    } 

    if (IMG_Init( IMG_INIT_PNG ) < 0) { // IMG_INIT_JPG | IMG_INIT_PNG
        std::cerr << "SDL init IMG fail. SDL_Error : " << IMG_GetError() << std::endl;
        return this->stop();
    }


    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) ) {
        std::cerr << "Warning: Linear texture filtering not enabled" << std::endl;
    }


    this->window = SDL_CreateWindow( this->windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->windowWidth, this->windowHeight, SDL_WINDOW_SHOWN );
    
    if( window == NULL ) {
        std::cerr << "SDL CreateWindow fail. SDL_Error : " << SDL_GetError() << std::endl;
        return this->stop();
    }

    this->screen = SDL_GetWindowSurface( window );

    //SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, "0");
    //SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, "2");
    //SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, 2);

}


void Sdl2Renderer::stop(){
    std::cout << "Stopping SDL2 Renderer." << std::endl;

    SDL_FreeSurface( this->screen );    
    SDL_DestroyWindow( this->window );
    
    IMG_Quit();
    SDL_Quit();
}


void Sdl2Renderer::showActor(Actor * actor) {
    SDL_Surface * heroImage = IMG_Load( actor->name.c_str() );

    if( heroImage == NULL ) {
        std::cerr << "SDL LoadBMP fail. SDL_Error : " << SDL_GetError() << std::endl;
        return this->stop();
    }

    /*this->scale -= 0.001;

    if (this->scale < 0.2){
        this->scale = 1;
    }*/

    SDL_Rect destRect;
    destRect.x = actor->position.x;
    destRect.y = actor->position.y;
    destRect.w = actor->width * this->scale;
    destRect.h = actor->height * this->scale;

    SDL_FillRect( this->screen, NULL, SDL_MapRGB( this->screen->format, 0xAA, 0xAA, 0xAA ) );
    SDL_BlitSurface( heroImage, NULL, this->screen, &destRect );
    //SDL_BlitScaled( heroImage, NULL, this->screen, &destRect );
    SDL_UpdateWindowSurface( this->window );

    SDL_FreeSurface( heroImage );
}

bool Sdl2Renderer::processEventsAndWaitForExit(){
    SDL_Event e;
    bool running = true;

    while(running) {

        if (SDL_PollEvent( &e ) == 0) {
            break;
        }
        
        if (e.type == SDL_MOUSEBUTTONDOWN) { 
            if(e.button.button == 1) {
                this->inputManager->inputPressed(InputManager::INPUT_POINTER_MAIN_BUTTON);
            } else {
                this->inputManager->inputPressed(InputManager::INPUT_POINTER_SECONDARY_BUTTON);
            }
        }
        
        if (e.type == SDL_MOUSEBUTTONUP) { 
            if(e.button.button == 1) {
                this->inputManager->inputReleased(InputManager::INPUT_POINTER_MAIN_BUTTON);
            } else {
                this->inputManager->inputReleased(InputManager::INPUT_POINTER_SECONDARY_BUTTON);
            }
        }

        if (e.type == SDL_MOUSEMOTION) { 
            this->inputManager->pointer.x = e.motion.x;
            this->inputManager->pointer.y = e.motion.y;
        }
        

        if (e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym==SDLK_LEFT){
                this->inputManager->inputPressed(InputManager::INPUT_LEFT_ARROW);
            }

            if(e.key.keysym.sym==SDLK_RIGHT){
                this->inputManager->inputPressed(InputManager::INPUT_RIGHT_ARROW);
            }

            if(e.key.keysym.sym==SDLK_RSHIFT){
                this->inputManager->inputPressed(InputManager::INPUT_SHIFT);
            }

            if(e.key.keysym.sym==SDLK_UP){
                this->inputManager->inputPressed(InputManager::INPUT_UP_ARROW);
            }

            if(e.key.keysym.sym==SDLK_DOWN){
                this->inputManager->inputPressed(InputManager::INPUT_DOWN_ARROW);
            }
        }

        if (e.type == SDL_KEYUP) {
            if(e.key.keysym.sym==SDLK_LEFT){
                this->inputManager->inputReleased(InputManager::INPUT_LEFT_ARROW);
            }
            
            if(e.key.keysym.sym==SDLK_RIGHT){
                this->inputManager->inputReleased(InputManager::INPUT_RIGHT_ARROW);
            }
            
            if(e.key.keysym.sym==SDLK_RSHIFT){
                this->inputManager->inputReleased(InputManager::INPUT_SHIFT);
            }

            if(e.key.keysym.sym==SDLK_UP){
                this->inputManager->inputReleased(InputManager::INPUT_UP_ARROW);
            }

            if(e.key.keysym.sym==SDLK_DOWN){
                this->inputManager->inputReleased(InputManager::INPUT_DOWN_ARROW);
            }
        }

        if( e.type == SDL_QUIT ) {
            running = false;
            std::cout << "Event was QUIT : will quit." << std::endl;
        }

    }

    return running;
}
