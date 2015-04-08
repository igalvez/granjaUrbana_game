#include "StateManager.h"
//#include "StateScene.h"


StateManager :: StateManager()
{

	SDLBase::inicializaSDL();
	dt = SDL_GetTicks();
  menustat = 0;
	estadoAtual = new StateMenu();
	estadoAtual->load(0);
	stack = 0;
 //srand(1);
  //srand(time(NULL));
	InputManager::getInstance()->update();
}


StateManager :: ~StateManager()
{
	delete estadoAtual;
}

void StateManager :: run()
{
  int frameStart, frameEnd ;
	bool quit = false;
	StateMenu menu;
	StateGame game;
  //int dt;
  frameEnd = 0;
  
  while(!quit){
    /*Calculando dt e atualizando frameEnd e frameStart */
    printf("\n COMECO WHILE \n");
    frameStart = SDL_GetTicks();
    dt = frameStart - frameEnd;
    if(dt<1500/30){
      SDL_Delay(1500/30 - dt);
    }
    frameEnd = frameStart;
		
    switch(estadoAtual->update(dt)){
			case 0:
				printf("\n estado 0 \n");
				break;
			case 1: //STATEMENU
        printf("\n 1 \n");
				stack = estadoAtual->unload(); 
				estadoAtual = new StateMenu();
				estadoAtual->load(stack);
				//menustat = 1;
				break;
			case 2: //STATEGAME
				printf("\n LOAAAAAAAAAAADINGGGGGGGGGGG  2 \n");
				stack = estadoAtual->unload();
        printf("\n DEU UNLOAD 2 %d\n",stack);
        //quit = true;
				//delete estadoAtual;
				estadoAtual = new StateGame();
        //printf("\n CARREGOU NOVO ESTADO 2 \n");
				estadoAtual->load(stack);

        //printf("\n FIM CASE  2 \n");
				break;
			case 3:  //STATEQUIT
				printf("\n 3 \n");
				quit = true;
				break;
      case 4:
				stack = estadoAtual->unload();
				estadoAtual = new StateScene();
				estadoAtual->load(stack);
				break;
      case 5:
				stack = estadoAtual->unload();
				estadoAtual = new StateWinLose();
				estadoAtual->load(stack);
				break;
			case 6:
				stack = estadoAtual->unload();
				estadoAtual = new StateInst();
				estadoAtual->load(stack);
				break;
    }
    estadoAtual->render();
    SDLBase::atualizarTela();
    printf("\n FIIIM WHILE \n");
  }
}

