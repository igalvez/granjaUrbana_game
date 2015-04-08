#include "StateScene.h"
#include "InputManager.h"

void StateScene :: load(int stack)
{

  final = new Animation("pictures/creditosFrame.png",500,8,false);
	som = new Audio("sound/POMBO_CUT2.mp3",1);
	som->play(-1);
  frame = 0;
  code = 0;
  endframe = 0;
  //final->setFrame(frame);
}
		
int StateScene :: unload()
{
  delete final;
	som->stop();
  return 0;
}


int StateScene :: update(int dt){

 InputManager::getInstance()->update();
	/*if(InputManager::getInstance()->iskeyDown(SDLK_RETURN)){
		frame++;
		if(frame > 15){
			frame = 0;
    }
		final->setFrame(frame);
	}*/
  if(endframe == 0){
  	if(!final->update(dt)){
			endframe = 1;
      final->setFrame(7);
  	}
  }
  
	if(InputManager::getInstance()->iskeyDown(SDLK_ESCAPE)){
		code = 1;
  }
	return code;
}

/*int StateScene :: update(int dt)
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
void StateScene :: render()
{
  final->render(0,0);
  //else
   //code = 1;
}
