#include "Timer.h"
#include <iostream>
#include <ctime>
#include <unistd.h>


Timer::Timer(){
    this->expectedDurationMs = 0;
    this->totalSleepMs = 0;
}

int Timer::elapsedMs(){
    return clock() / (CLOCKS_PER_SEC / 1000);
}

void Timer::frame() {
    this->lastStepCallMs = this->totalSleepMs + this->elapsedMs();
    std::cout << "FRAME : " << this->lastStepCallMs << " ms" << std::endl;
}

int  Timer::durationSinceLastFrame() {
    int nowMs = this->totalSleepMs + this->elapsedMs();
    int effectiveMs = nowMs - this->lastStepCallMs;
   
    std::cout << "DurationSinceLastFrame :" << std::endl;
    std::cout << "Now : " << nowMs << " ms" << std::endl;
    std::cout << "Last frame : " << this->lastStepCallMs << " ms" << std::endl;
    std::cout << "Effective : " << effectiveMs << " ms" << std::endl;

    return effectiveMs;
}

void Timer::waitIfNeeded() {
    std::cout << " * Check if wait is needed" << std::endl;
    
    int effectiveMs = this->durationSinceLastFrame();
    int diffMs = this->expectedDurationMs - effectiveMs;

    std::cout << "Expected : " << this->expectedDurationMs << " ms" << std::endl;
    std::cout << "Diff : " << diffMs << " ms" << std::endl;

    if (effectiveMs < this->expectedDurationMs) {
      return this->sleepMs(diffMs);
    } 

    std::cout << "Do not wait." << std::endl;

}

void Timer::sleepMs(int millisec) {
    std::cout << "Wait: " << millisec << " ms" << std::endl;
    usleep(millisec * 1000);
    this->totalSleepMs += millisec;
}
