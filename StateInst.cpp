#include "StateInst.h"

void StateInst :: load(int stack)
{
  


  bg = new Sprite("pictures/inst.png");

	returnState = 0;
}

int StateInst :: unload()
{
	delete bg;

	return 0;
}

int StateInst :: update(int dt)
{
	InputManager::getInstance()->update();

	if(InputManager::getInstance()->iskeyDown(SDLK_ESCAPE))
		returnState = 1;
  return returnState;
}

void StateInst :: render()
{
	bg->render(0,0);

}

