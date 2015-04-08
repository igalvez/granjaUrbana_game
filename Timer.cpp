#include "Timer.h"

void Timer :: start(){
	initialTime = SDL_GetTicks();
	//timePaused = 0;
	paused = false;
}

void Timer :: pause(){
	pauseTime = SDL_GetTicks();
	paused = true;
}

void Timer :: resume(){
  
  //timePaused = SDL_GetTicks() - pauseTime;
  initialTime = SDL_GetTicks();// - timePaused;
	//timePaused = 0;
	paused = false;
}

int Timer :: getTime(){
  int aux;
	if(paused){
		aux = SDL_GetTicks() - pauseTime;
		//printf("
  }
	else{
		aux = SDL_GetTicks() - initialTime;
	}
  return aux;

}
