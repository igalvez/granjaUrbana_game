#include "StateMenu.h"

#define BOTOESX 234


#define JOGARY 184
#define JOGARX 530
#define JOGARW 244
#define JOGARH 96
#define AJUDAY 294
#define AJUDAX 508
#define AJUDAW 269
#define AJUDAH 106
#define STORYY 415
#define STORYX 448
#define STORYW 327
#define STORYH 85
#define SAIRY 504
#define SAIRX 547
#define SAIRW 162
#define SAIRH 66

#define BOTAOW 370
#define BOTAOH 90

void StateMenu :: load(int stack)
{
  bg = new Sprite("pictures/menuFundo.png");
  jogar_on = new Sprite("pictures/jogarOn.png");
	jogar_off = new Sprite("pictures/jogarOff.png");
	ajuda_on = new Sprite("pictures/opcoesOn.png");
	ajuda_off = new Sprite("pictures/opcoesOff.png");
	story_on = new Sprite("pictures/historiasOn.png");
	story_off = new Sprite("pictures/historiasOff.png");
  sair_on = new Sprite("pictures/sairOn.png");
	sair_off = new Sprite("pictures/sairOff.png");

	frameMenu1 = new Animation("pictures/frameMenu1.jpg",100,15,false);
	frameMenu2 = new Animation("pictures/frameMenu2.jpg",100,15,false);
	///frameMenu
  
  
  animateMenu = stack;
  if(!stack)	
		animacao = 1;
  else
		animacao = 0;
		
  jogar = 0;
	ajuda = 0;
	story = 0;
 	sair = 0;

 /* menu = new Text("/usr/share/fonts/truetype/ttf-liberation/LiberationSans-Regular.ttf","MENU",380,100,40);
	instrucoes = new Text("/usr/share/fonts/truetype/ttf-liberation/LiberationSans-Regular.ttf", "1 - instrucoes de jogo",300,180,25);
  voltar = new Text("/usr/share/fonts/truetype/ttf-liberation/LiberationSans-Regular.ttf", "2 - jogo",300,220,25);
	sair = new Text("/usr/share/fonts/truetype/ttf-liberation/LiberationSans-Regular.ttf" , "3 - sair",300,260, 25);*/
  music = new Audio("sound/Pombo_Menu.mp3",1);
  music->play(-1);
	returnState = 0;
}

int StateMenu :: unload()
{
	delete bg;
  delete jogar_on;
	delete jogar_off;
	delete ajuda_on;
	delete ajuda_off;
	delete story_on;
	delete story_off;
  delete sair_on;
	delete sair_off; 
	delete frameMenu1;
	delete frameMenu2;
  music->stop();
	return 0;
}

int StateMenu :: update(int dt)
{
	InputManager::getInstance()->update();
  
 /*if((!animateMenu)){
    if(contFrame == 1){
    	if(frameMenu1->update(dt)==false)
				printf(" \n CABO FRAMEMENU1 \n");
				contFrame = 2;
    }
    else if(contFrame == 2){
    	if(!frameMenu2->update(dt))
				contFrame = 0;
				animateMenu = 1;
		}
  }*/
  if(animacao==1){
		if(!frameMenu1->update(dt)){
			animacao = 2;
    }
  }
  else if(animacao == 2){
		if(!frameMenu2->update(dt))
			animacao = 0;
  }
  else{
  	if(InputManager::getInstance()->isMouseUp(SDL_BUTTON_RIGHT)){
			int mouseX, mouseY;
			SDL_GetMouseState( &mouseX, &mouseY );

  		jogar = 0;
			ajuda = 0;
			story = 0;
			sair = 0;
    
    	if((mouseX > JOGARX)&&(mouseX < (JOGARX+JOGARW))&&(mouseY > JOGARY)&&(mouseY < (JOGARY+JOGARH)))
				jogar = 1;
   		else if((mouseX > AJUDAX)&&(mouseX < (AJUDAX+AJUDAW))&&(mouseY > AJUDAY)&&(mouseY < (AJUDAY+AJUDAH)))
				ajuda = 1;
			else if((mouseX > STORYX)&&(mouseX < (STORYX+STORYW))&&(mouseY > STORYY)&&(mouseY < (STORYY+STORYH)))
				story = 1;
    	else if((mouseX > SAIRX)&&(mouseX < (SAIRX+SAIRW))&&(mouseY > SAIRY)&&(mouseY < (SAIRY+SAIRH)))
				sair = 1;
  	}
		
  	if(InputManager::getInstance()->isMouseDown(SDL_BUTTON_LEFT)){
			int mouseX, mouseY;
			SDL_GetMouseState( &mouseX, &mouseY );

		    
    	if((mouseX > JOGARX)&&(mouseX < (JOGARX+JOGARW))&&(mouseY > JOGARY)&&(mouseY < (JOGARY+JOGARH)))
				returnState = 2;
   		else if((mouseX > AJUDAX)&&(mouseX < (AJUDAX+AJUDAW))&&(mouseY > AJUDAY)&&(mouseY < (AJUDAY+AJUDAH)))
				returnState = 6;
			else if((mouseX > STORYX)&&(mouseX < (STORYX+STORYW))&&(mouseY > STORYY)&&(mouseY < (STORYY+STORYH)))
				returnState = 4;
    	else if((mouseX > SAIRX)&&(mouseX < (SAIRX+SAIRW))&&(mouseY > SAIRY)&&(mouseY < (SAIRY+SAIRH)))
				returnState = 3;

  	}
  }
  return returnState;
}



void StateMenu :: render()
{
	
 
 if(animacao==1){
		frameMenu1->render(0,0);
  }
  else if(animacao==2){
		frameMenu2->render(0,0);
  }
  else{
  	bg->render(0,0);
  
  
  	if(jogar)
			jogar_on->render(JOGARX, JOGARY);
  	else
			jogar_off->render(JOGARX, JOGARY);

  	if(ajuda)
			ajuda_on->render(AJUDAX, AJUDAY);
  	else
			ajuda_off->render(AJUDAX, AJUDAY);

  	if(story)
			story_on->render(STORYX, STORYY);
  	else
			story_off->render(STORYX, STORYY);

  	if(sair)
			sair_on->render(SAIRX, SAIRY);
  	else
			sair_off->render(SAIRX, SAIRY);

 }

}

