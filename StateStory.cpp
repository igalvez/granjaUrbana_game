#include "StateStory.h"
#include "InputManager.h"

void StateStory :: load(int stack)
{

  final = new Animation("pictures/frame_sheet_final.png",900,16,true);
  frame = 0;
  code = 0;
  final->setFrame(frame);
}
		
int StateStory :: unload()
{
  delete final;
  return 0;
}


int StateStory :: update(int dt){
	if(InputManager::getInstance()->iskeyDown(SDLK_RETURN)){
		frame++;
		if(frame > 15){
			frame = 0;
    }
		final->setFrame(frame);
	}
	if(InputManager::getInstance()->iskeyDown(SDLK_ESCAPE)){
		code = 1;
  }
	return code;
}

/*int StateStory :: update(int dt)
{
  printf("\n INICIO UPDATE STORYYY \n");
	if(InputManager::getInstance()->iskeyDown(SDLK_ESCAPE)){
			code = 1;
       printf("\n TESTCODE \n");
	}
	else if(InputManager::getInstance()->iskeyDown(SDLK_RETURN)){
  	frame++;
    if(frame>15)
			frame = 0;
    final->setFrame(frame);
    printf("\n APERTOU RETURN \n");
	}
 //final->setFrame(frame);
   printf("\n FIM UPDATE STORYYY \n");
  return code;
}			*/
void StateStory :: render()
{
  final->render(0,0);
  //else
   //code = 1;
}
