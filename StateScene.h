#include "SDLBase.h"
#include "State.h"
#include "InputManager.h"
#include "Animation.h"
#include "Audio.h"
#ifndef STATESCENE_H	
#define STATESCENE_H

class StateScene : public State
{
	private:
		Animation *final;
		Audio *som;
    int code;
    int frame;
    int endframe;
   

  public:
		StateScene(){};
		void load(int stack);
		int unload();
		int update(int dt);
		void render();

};

#endif
   
    
