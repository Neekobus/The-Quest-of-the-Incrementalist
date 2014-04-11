#include "MainController.h"
#include <ctime>

MainController::MainController(){
   this->running = false;
   this->renderer = NULL;
   this->actor = NULL;
}

void MainController::run(){
	this->renderer->start();
	this->running = true;

  int lastStepCallMs = clock() / (CLOCKS_PER_SEC / 1000);
  int expectedDuration = 1000/3;

  while(this->running) {
    int nowMs = clock() / (CLOCKS_PER_SEC / 1000);
    int diffMs = nowMs - lastStepCallMs;

    std::cout << "Now " << nowMs << " ms" << std::endl;
    std::cout << "Last " << lastStepCallMs << " ms" << std::endl;
    std::cout << "Diff " << diffMs << " ms" << std::endl;
    std::cout << "Expected  " << expectedDuration << " ms" << std::endl;

    if (diffMs < expectedDuration) {
      std::cout << "[Wait] " ;
      //wait
      continue;
    }

    std::cout << "[Work] " << std::endl;
    this->step();
    lastStepCallMs = clock() / (CLOCKS_PER_SEC / 1000);
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