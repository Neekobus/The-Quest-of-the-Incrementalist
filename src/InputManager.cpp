#include "InputManager.h"
#include <iostream>

int InputManager::INPUT_DOWN_ARROW = 1;
int InputManager::INPUT_UP_ARROW = 2;
int InputManager::INPUT_LEFT_ARROW = 3;
int InputManager::INPUT_RIGHT_ARROW = 4;
int InputManager::INPUT_SHIFT = 5;

InputManager::InputManager(){
    this->pressed = std::map<int, bool>();
}

InputManager::~InputManager(){
    this->pressed.clear();
}

void InputManager::inputPressed(int code) {
    this->pressed[code] = true;
    std::cout << "Input pressed : " << code << std::endl;
 }

void InputManager::inputReleased(int code) {
    this->pressed.erase( code );
    std::cout << "Input released : " << code << std::endl;
}

bool InputManager::isPressed(int code) {
    if (this->pressed.count(code) == 0) {
        return false;
    }

    return this->pressed[code];
}

