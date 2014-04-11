#ifndef TIMERH
#define TIMERH

#include <string>

class Timer {    
	protected:
		int elapsedMs();
		void sleepMs(int millisec);
		int lastStepCallMs;
		int totalSleepMs;

    public:
        Timer();
        int expectedDurationMs;
        
        void frame();
        int  durationSinceLastFrame();
        void waitIfNeeded();

};
#endif