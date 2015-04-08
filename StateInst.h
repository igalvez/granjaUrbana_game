#include "State.h"
#include "Sprite.h"
#include "Text.h"
#include "InputManager.h"


#ifndef STATEINST_H
#define STATEINST_H

class StateInst : public State {
	
	private:
		Sprite *bg;
		int returnState;
	public:
		StateInst(){};
		void load(int stack);
		int unload();
		int update(int dt);
		void render();
};

#endif
