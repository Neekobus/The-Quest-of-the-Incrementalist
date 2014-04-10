#include "MainController.h"

MainController::MainController(){
   this->running = false;
   this->renderer = NULL;
   this->actor = NULL;
}

void MainController::run(){
	this->renderer->start();
	this->running = true;

    while(this->running) {
        this->step();
    }
    
    this->renderer->stop();
}

void MainController::step(){
	this->actor->x = this->actor->x + 1;
    this->renderer->showActor(this->actor);
    this->running = this->renderer->waitForExit(); 
}

MainController::~MainController(){
   	this->running = false;
   	this->renderer = NULL;
   	this->actor = NULL;
}