#include "SDLBase.h"


#ifndef STATE_H
#define STATE_H
class State{
	public:
		virtual void load(int stack = 0) = 0;
		virtual int unload() = 0;
		virtual int update(int dt) = 0;
		virtual void render() = 0;
};

#endif
