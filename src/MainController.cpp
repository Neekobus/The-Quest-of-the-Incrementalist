#include "MainController.h"
#include <ctime>
#include <unistd.h>

MainController::MainController(){
   this->running = false;
   this->renderer = NULL;
   this->actor = NULL;
}

void MainController::run(){
	this->renderer->start();
	this->running = true;

  int lastStepCallMs = clock() / (CLOCKS_PER_SEC / 1000);
  int expectedDuration = 1000/30; //1000/2; //1000/60
  int totalSleepMs = 0;

  while(this->running) {
    int nowMs = totalSleepMs + clock() / (CLOCKS_PER_SEC / 1000);
    int effectiveMs = nowMs - lastStepCallMs;
    int diffMs = expectedDuration - effectiveMs;

    std::cout << "Now " << nowMs << " ms" << std::endl;
    std::cout << "Last " << lastStepCallMs << " ms" << std::endl;
    std::cout << "Effective " << effectiveMs << " ms" << std::endl;
    std::cout << "Expected  " << expectedDuration << " ms" << std::endl;
    std::cout << "Diff  " << diffMs << " ms" << std::endl;

    if (effectiveMs < expectedDuration) {
      std::cout << "[Wait: " << diffMs << " ms ] " << std::endl;
      usleep(diffMs * 1000);
      totalSleepMs += diffMs;
      continue;
    }

    std::cout << "[Work] " << std::endl;
    this->step(effectiveMs);
    lastStepCallMs =  totalSleepMs + clock() / (CLOCKS_PER_SEC / 1000);
  }
    
  this->renderer->stop();
}

void MainController::step(float elapsedMs){
  float actorVelocity = 100; 
  float elapsedSec = elapsedMs / 1000;
  float move = actorVelocity * elapsedSec;

  std::cout << "Velocity : " << actorVelocity << " px/s" << std::endl;
  std::cout << "Elapsed : " << elapsedSec << " s" << std::endl;
  std::cout << "Move : " << move << " px" << std::endl;

	this->actor->x = this->actor->x + move;
  this->renderer->showActor(this->actor);
  this->running = this->renderer->waitForExit(); 
}

MainController::~MainController(){
   	this->running = false;
   	this->renderer = NULL;
   	this->actor = NULL;
}