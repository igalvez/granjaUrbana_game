#include "SDLBase.h"

#ifndef TIMER_H
#define TIMER_H

class Timer{
	private:
		int initialTime;
		int pauseTime;
		

	public:
		bool paused;
		void start();
		void pause();
		void resume();
		int getTime();

};

#endif
