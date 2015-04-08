#include "SDLBase.h"
#include "State.h"
#include "InputManager.h"
#include "Animation.h"

#ifndef STATESTORY_H	
#define STATESTORY_H

class StateStory : public State
{
	private:
		Animation *final;
    int code;
    int frame;

  public:
		StateStory(){};
		void load(int stack);
		int unload();
		int update(int dt);
		void render();

};

#endif
   
    
