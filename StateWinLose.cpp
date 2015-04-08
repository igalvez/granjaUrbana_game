#include "StateWinLose.h"

void StateWinLose :: load(int stack)
{
  
	
		bg = new Sprite("pictures/dove_final.png");
    cenaFinal = new Animation("pictures/frame_sheet_final.png",1600,16, false);
		sfx = new Audio("sound/Pombo_Ganha.wav",0);
    //sfx->play(1);
		//music->play(1);
    animacao = 1;
	  returnState = 0;
}

int StateWinLose :: unload()
{
	delete bg;
  sfx->stop();
	//delete texto;
 // music->stop();
  delete cenaFinal;
 // delete sfx;

	return 0;
}

int StateWinLose :: update(int dt)
{
 
  if(animacao){
		if(!cenaFinal->update(dt)){
			animacao = 0;
      sfx->play(1);
    }
  }
  if(!animacao){

		InputManager::getInstance()->update();

		if(InputManager::getInstance()->iskeyDown(SDLK_RETURN))
			returnState = 1;
  	
	}
  return returnState;
}

void StateWinLose :: render()
{
	bg->render(0,0);
  if(animacao)
    cenaFinal->render(0,0);
	//texto->render(0,80);
}

