#include "State.h"
#include "Sprite.h"
#include "Text.h"
#include "InputManager.h"
#include "Audio.h"
#include "Animation.h"

#ifndef STATEWINLOSE_H
#define STATEWINLOSE_H

class StateWinLose : public State {
	
	private:
		Sprite *bg;
    //Text *texto;
		Audio *sfx;
    int animacao;
		int returnState;
	public:
    Animation *cenaFinal;
		StateWinLose(){};
		void load(int stack);
		int unload();
		int update(int dt);
		void render();
};

#endif
