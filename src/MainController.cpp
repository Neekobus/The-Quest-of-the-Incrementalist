#include "MainController.h"
#include "Timer.h"

MainController::MainController(){
   this->running = false;
   this->renderer = NULL;
   this->actor = NULL;
}

void MainController::run(){
	this->renderer->start();
	this->running = true;

  Timer timer;
  timer.expectedDurationMs = 1000 / 30;
  timer.frame();
  
  while(this->running) {
    timer.waitIfNeeded();

    int elapsedTime = timer.durationSinceLastFrame();
    this->step(elapsedTime);
    
    timer.frame();
  }
    
  this->renderer->stop();
}

void MainController::step(float elapsedMs){
	this->actor->move(elapsedMs);
  this->renderer->showActor(this->actor);
  this->running = this->renderer->processEventsAndWaitForExit(); 
}

MainController::~MainController(){
   	this->running = false;
   	this->renderer = NULL;
   	this->actor = NULL;
}