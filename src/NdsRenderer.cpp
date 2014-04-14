
#include "NdsRenderer.h"
#include <nds.h>

NdsRenderer::NdsRenderer(std::string winTitle){
    this->windowTitle = winTitle;
}

void NdsRenderer::screenColor(int color){
    int i;
    for(i = 0; i < 256 * 192; i++){
        VRAM_A[i] = RGB15(color, 0, 0);
    }
}

void NdsRenderer::start(){
    std::cout << "Starting NDS Renderer..." << std::endl;

    irqInit();
    irqEnable(IRQ_VBLANK);

    consoleDemoInit();
    videoSetMode(MODE_FB0);
    vramSetBankA(VRAM_A_LCD);
    screenColor(3);


}


void NdsRenderer::stop(){
    std::cout << "Stopping NDS Renderer." << std::endl;
}


void NdsRenderer::showActor(Actor * actor) {
    swiWaitForVBlank();
    screenColor(3);

    int col; //256 * 192
    int line;
    int i;
    

    
    
    for(line = (int) actor->position.y; line <= actor->position.y + actor->height; line++) {
        for(col = (int) actor->position.x; col < actor->position.x + actor->width ; col++) {
            i = (line * SCREEN_WIDTH) + col;
            VRAM_A[i] = RGB15(30, 30, 0);

        }
    }

    i = ((int) actor->position.y * SCREEN_WIDTH) + (int)actor->position.x;
    VRAM_A[i-1] = RGB15(0, 30, 30);
    VRAM_A[i] = RGB15(0, 30, 30);
    VRAM_A[i+1] = RGB15(0, 30, 30);
    
    VRAM_A[i-SCREEN_WIDTH-1] = RGB15(0, 30, 0);
    VRAM_A[i-SCREEN_WIDTH] = RGB15(0, 30, 0);
    VRAM_A[i-SCREEN_WIDTH+1] = RGB15(0, 30, 0);

    VRAM_A[i+SCREEN_WIDTH-1] = RGB15(0, 30, 30);
    VRAM_A[i+SCREEN_WIDTH] = RGB15(0, 30, 30);
    VRAM_A[i+SCREEN_WIDTH+1] = RGB15(0, 30, 30);
    
}

bool NdsRenderer::processEventsAndWaitForExit(){


    //touchPosition touch;
    scanKeys();
    int keys = keysHeld();
    //touchRead(&touch);

    this->inputManager->inputReleased(InputManager::INPUT_UP_ARROW);
    this->inputManager->inputReleased(InputManager::INPUT_DOWN_ARROW);
    this->inputManager->inputReleased(InputManager::INPUT_LEFT_ARROW);
    this->inputManager->inputReleased(InputManager::INPUT_RIGHT_ARROW);

    if(keys & KEY_UP) {
        this->inputManager->inputPressed(InputManager::INPUT_UP_ARROW);        
    }

    if(keys & KEY_DOWN) {
        this->inputManager->inputPressed(InputManager::INPUT_DOWN_ARROW);        
    }

    if(keys & KEY_LEFT) {
        this->inputManager->inputPressed(InputManager::INPUT_LEFT_ARROW);        
    }

    if(keys & KEY_RIGHT) {
        this->inputManager->inputPressed(InputManager::INPUT_RIGHT_ARROW);        
    }

    
    //input manager
    //pos = touch.py * 256;
    //size = touch.px /  5;

    return true;
}

