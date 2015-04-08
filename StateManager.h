#include "SDLBase.h"
#include "InputManager.h"
#include <time.h>
#include "State.h"
#include "StateMenu.h"
#include "StateGame.h"
#include "StateInst.h"
#include "StateWinLose.h"
#include "StateScene.h"

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class StateManager{
	private:
		State *estadoAtual;
		int stack;
    int menustat;
		int dt;
	public:
		StateManager();
		~StateManager();
		void run();
};

#endif
