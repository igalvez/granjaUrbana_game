#include "StateGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include <sstream>
#include <queue>


#define TESTE perror("teste");
#define FINAL 60000
#define DIV1 15100
#define DIV2 35000
#define DIV3 40000

using namespace std;

float StateGame :: cameraX = 0;
float StateGame :: cameraY = 0;

void StateGame :: load(int stack){

  string img_tileset = "pictures/tileset.png";
  int x ;
  int y;
	isPause = 0;
  music = new Audio("sound/Pombo_Fase.mp3",1);
  sfx = new Audio("sound/POMBO_GRITO.wav",0);
  sfxBoost = new Audio("sound/PomboBoost0.wav",0);
	music->play(-1);
  srand(999727);//srand(time(NULL));
  //coolDown.start();
  SDLBase::inicializaSDL();
  speedCamX = 12;
  cameraSpeedX = 0;
  cameraSpeedY = 0;
  cameraX = 0;
  cameraY = 0;
  boomX = 0;
  boomY = 0;
  frangoX = 0;
	frangoY = 0;
  cont = 0;
  n_pipocas = 0;
  stateReturn = 0;

 
  bg = new Sprite("pictures/fundo5.png");
  buttonPause = new Sprite("pictures/pause.png");
  //blocoSprite = new Sprite("pictures/bloco.png");
  doveAnimation = new Animation("pictures/sprite_Dove.png",50,8,true);
  borusAnimation = new Animation("pictures/sprite_Borus.png",60,8,true);
  dove = new DirectionObject(doveAnimation,200,300);
  borus = new NPCObject(borusAnimation,-160,0);

  balao = new Sprite("pictures/balaog.png");
  aviao = new Sprite("pictures/aviao_papel.png");
  doveFinal = new Sprite("pictures/dove_final.png");
  pipocaSprite = new Sprite("pictures/pipoca.png");
  
  /*TELAS DE STATUS*/
	status0 = new Sprite("pictures/px0.png");
  status1 = new Sprite("pictures/px1.png");
	status2 = new Sprite("pictures/px2.png");
	status3 = new Sprite("pictures/px3.png");

  /*MUROS */
  muroSprite = new Sprite("pictures/muroFundo.png");
  muro = new Obstaculo(muroSprite, MUROX1, 0, 0, 0);
  muro2 = new Obstaculo(muroSprite, MUROX2, 0, 0, 0);
  arSprite = new Sprite("pictures/ar_condicionado.png");
	air[0] = new Ar(arSprite,MUROX1+ARX1,ARY1);
	air[1] = new Ar(arSprite,MUROX1+ARX2,ARY2);
  air[2] = new Ar(arSprite,MUROX1+ARX3,ARY3);
	air[3] = new Ar(arSprite,MUROX1+ARX4,ARY4);
  air[4] = new Ar(arSprite,MUROX1+ARX5,ARY5);
	air[5] = new Ar(arSprite,MUROX1+ARX6,ARY6);
  air[6] = new Ar(arSprite,MUROX1+ARX7,ARY7);
	air[7] = new Ar(arSprite,MUROX1+ARX8,ARY8);
  
	air[8] = new Ar(arSprite,MUROX2+ARX1,ARY1);
	air[9] = new Ar(arSprite,MUROX2+ARX2,ARY2);
  air[10] = new Ar(arSprite,MUROX2+ARX3,ARY3);
	air[11] = new Ar(arSprite,MUROX2+ARX4,ARY4);
  air[12] = new Ar(arSprite,MUROX2+ARX5,ARY5);
	air[13] = new Ar(arSprite,MUROX2+ARX6,ARY6);
  air[14] = new Ar(arSprite,MUROX2+ARX7,ARY7);
	air[15] = new Ar(arSprite,MUROX2+ARX8,ARY8);

  tileSet = new TileSet(374, 300, img_tileset);

  boom = new Animation("pictures/BoomSprite4.png",100,12,false);
  doveDepenado = new Animation("pictures/spriteDepenado.png",200,8,true);
  printf("\n  ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ STAAACK %d\n",stack);

  //Conferindo save Point
  switch(stack){
    case 0: 
						printf(" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX CASO 0 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
            break;
  	case 1: 
						cameraX = SAVEP1; 
            dove->x = SAVEP1 + 200 ;
    				borus->x = SAVEP1 - 160;
            printf(" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX CASO 1 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    				break;
		case 2: 
            cameraX = SAVEP2; 
            dove->x = SAVEP2 + 200;
						borus->x = SAVEP2 - 160;
            printf(" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX CASO 2 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
            break;
  }
  

  //Carregando os Obstaculos
  if(stack==0)
  {
  	for(int i=0; i<=70; i++){
    	int z = rand() % 2;
    	Obstaculo *newBlock;
 			x = (rand() % (DIV1)); //42949600;
			y = rand() % 550;
    	x+=600;

    	if(z ==0)
				newBlock = new Obstaculo(aviao,(float)x,(float)y, (float)100, (float)51);
    	else
      	newBlock = new Obstaculo(balao,(float)x,(float)y, (float)60, (float)67);

    	blocos.push_back(newBlock);
  	}
	}
  if(stack <2)
  {
		for(int i=0; i<=70; i++){
    	int z = rand() % 2;
    	Obstaculo *newBlock;
 			x = (rand() % (15000)); //42949600;
			y = rand() % 550;
    	x+=20000;

    	if(z ==0)
				newBlock = new Obstaculo(aviao,(float)x,(float)y, (float)100, (float)51);
    	else
      	newBlock = new Obstaculo(balao,(float)x,(float)y, (float)60, (float)67);

    	blocos.push_back(newBlock);
  	}
  }
  for(int i=0; i<=100; i++){
    	int z = rand() % 2;
    	Obstaculo *newBlock;
 			x = (rand() % (20000)); //42949600;
			y = rand() % 550;
    	x+=DIV3;

    	if(z ==0)
				newBlock = new Obstaculo(aviao,(float)x,(float)y, (float)100, (float)51);
    	else
      	newBlock = new Obstaculo(balao,(float)x,(float)y, (float)60, (float)67);

    	blocos.push_back(newBlock);
  }
  /* PIPOCAS */

	pipocas[0] = new Obstaculo(pipocaSprite,14860, 200, POPCORNW, POPCORNH);
	pipocas[1] = new Obstaculo(pipocaSprite,15290, 405, POPCORNW, POPCORNH);
	pipocas[2] = new Obstaculo(pipocaSprite,15856, 320, POPCORNW, POPCORNH);
	pipocas[3] = new Obstaculo(pipocaSprite,17490, 286, POPCORNW, POPCORNH);
	pipocas[4] = new Obstaculo(pipocaSprite,7060, 500, POPCORNW, POPCORNH);

	pipocas[5] = new Obstaculo(pipocaSprite,22200, 321, POPCORNW, POPCORNH);
	pipocas[6] = new Obstaculo(pipocaSprite,34200, 98, POPCORNW, POPCORNH);
	pipocas[7] = new Obstaculo(pipocaSprite,37120, 310, POPCORNW, POPCORNH);
	pipocas[8] = new Obstaculo(pipocaSprite,42540, 429, POPCORNW, POPCORNH);
	pipocas[9] = new Obstaculo(pipocaSprite,16140, 305, POPCORNW, POPCORNH);


	pipocas[10] = new Obstaculo(pipocaSprite,44352, 102, POPCORNW, POPCORNH);
	pipocas[11] = new Obstaculo(pipocaSprite,46376, 123, POPCORNW, POPCORNH);
	pipocas[12] = new Obstaculo(pipocaSprite,48652, 220, POPCORNW, POPCORNH);
	pipocas[13] = new Obstaculo(pipocaSprite,48990, 435, POPCORNW, POPCORNH);
	pipocas[14] = new Obstaculo(pipocaSprite,51860, 310, POPCORNW, POPCORNH);
	pipocas[15] = new Obstaculo(pipocaSprite,54231, 25, POPCORNW, POPCORNH);
	pipocas[16] = new Obstaculo(pipocaSprite,55860, 325, POPCORNW, POPCORNH);
	pipocas[17] = new Obstaculo(pipocaSprite,57290, 275, POPCORNW, POPCORNH);
	pipocas[18] = new Obstaculo(pipocaSprite,58060, 92, POPCORNW, POPCORNH);
	pipocas[19] = new Obstaculo(pipocaSprite,3980, 234, POPCORNW, POPCORNH);


	
 /*	Obstaculo *newPop= new Obstaculo(pipocaSprite, 1000, 400, 39 , 49);
  pipocas.push_back(newPop);
  newPop= new Obstaculo(pipocaSprite, 5000, 50, 39 , 49);
  pipocas.push_back(newPop);*/
  //delete newPop;
		
	//MUSICA

  
  //sfx = new Audio("sfx/boom.wav",0);



  /* Costruir mapa */
  
  tileMap = new TileMap("tileMap.txt", tileSet);  

  printf("\n FIIIM LOAAAAD \n");
  
}

int StateGame :: unload(){
  printf("\n SAVE STACK = %d\n", saveStack);

  delete bg;
  if(dove!=NULL){
    if(dove->x < FINAL){
			music->stop();
    }
		delete dove;
  }
  else {
		sfx->stop();
    music->stop();
  }
	delete doveAnimation;
  delete doveDepenado;
  delete borus;
  delete borusAnimation;
 
  delete aviao;
  delete balao;
  delete tileSet;
  delete tileMap;
  delete boom;
  delete muroSprite;
  delete muro;
  delete muro2;
  
  for(int i=0 ; i<NPIPOCAS; i++){
		delete pipocas[i];
  }
  for(int i=0; i<16; i++){
		delete air[i];
  }
 
  //if(isPause == 0){
  
 // if(isPause == 0)
	//	sfx->stop();
  //}
  blocos.clear();
  
  return saveStack; //saveStack;
}
void StateGame :: processEvents(){

        printf(" \n PROCESS EVENTS\n");
        InputManager::getInstance()->update();


				if(InputManager::getInstance()->iskeyDown(SDLK_RETURN)){
					if(isPause == 0){
            isPause = 1;
						//pause();
            //return;
          }
					else{
						isPause = 0;
						music->resume();
          }
				}
        if(InputManager::getInstance()->iskeyDown(SDLK_ESCAPE)){
           /* SDL_Event quit;
            quit.type = SDL_QUIT;
            SDL_PushEvent( &quit );*/
            printf("APERTOU ESC!!!");
						stateReturn = 1;
            if(isPause){
						  music->resume();
              isPause = 0;
            }
             
            
        }
        if(InputManager::getInstance()->iskeyDown(SDLK_q)){
					cameraX = 59000;
					dove->x = cameraX + 400;
					borus->x = cameraX - 160;
        }
	      printf(" \n STATE RETURN %d\n", stateReturn);
        printf(" \n FIIM PROCESS EVENTS\n");
			  
}  
 

int StateGame :: update(int dt)
{
   
  //int x, y;
  processEvents(); 	
  if(isPause == 1)
			pause();

  printf(" \n UPDATEE\n");
  if(dove!=NULL){

    borus->update(dt, cameraX, dove->x, dove->y);
    borus->x += speedCamX + borus->speedx*dt;

    if(dove->update(dt) == 0){
			 dove->x  += speedCamX;
       cameraX += speedCamX;
    }
    else{
			if(dove->sound == 1){
				//sfxBoost->play(1);
				dove->sound = 0;
      }
//dasda
			dove->x += speedCamX;
			cameraX += speedCamX + dove->speedx*dt;
      printf("\n BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOST \n");
    }
    

    if(dove->x > FINAL){
			stateReturn = 5;
    }
		
    
  }
  else{
    if(frangoY>=700)
      stateReturn = 2;
  }
   

    //borus->box.x = cameraX + borus->speedx*dt -80;
   
    //cameraY = 0;
    
    //printf("\n CAMERAX DEBUG %f\n", cameraX);


     //BLOCOS
    /*if(speedCamX!=0){
    	if((int)cameraX % (160*speedCamX) == 0){
				for(vector<Obstaculo*>::iterator it=blocos.begin(); it != blocos.end(); it++)
				{
						Obstaculo *block = *it;
        	  if((block->box.x + block->box.w)<cameraX){
        	  	if(it+1 != blocos.end()){
        	    	it = blocos.erase(it);
        	   	  it -1;
        	  	}
        	  	else {
        	    	blocos.erase(it);
        	    	it = blocos.end() -1 ;
        	  	}
        	  }
      	}

      	for(int i=0; i<10 ; i++){
          int z = rand() % 2;
          Obstaculo *newBlock;
					x = (rand() % (speedCamX*160)); //42949600;
					y = rand() % 550;
    			x+=cameraX+speedCamX*160;

          if(z ==0)
		     		newBlock = new Obstaculo(aviao,(float)x,(float)y, (float)100, (float)51);
    			else
      			newBlock = new Obstaculo(balao,(float)x,(float)y, (float)60, (float)70);

   			  blocos.push_back(newBlock);
      	}
    	}
    }				*/

 //Conferindo explosao
  if((boomX!=0)&&(boomY!=0)){
    if(!boom->update(dt)){
      frangoX = boomX;
      frangoY = boomY;
      boomX = 0;
      boomY = 0;
      
      
    }
  }
 //Iniciando animacao de frango depenado
  if((frangoX!=0)&&(frangoY!=0)){
      doveDepenado->update(dt);
      if(cont<15)
        cont++;
      else{
        
      	frangoY += 20;
      	frangoX += speedCamX;
        cont++;
      }
  }

  if(dove!=NULL) 
    checkCollision(dt);
 
	return stateReturn;
  
  
}

void StateGame :: render()
{
  printf("\n ENTROU NO RENDER\n");

  bg->render(0,0);
	tileMap->renderLayer(SCROLL_C1*cameraX, SCROLL_C1*cameraY,1);
  tileMap->renderLayer(SCROLL_C2*cameraX, SCROLL_C2*cameraY,0);
  muro->render(cameraX, cameraY);
  muro2->render(cameraX,cameraY);

  for(int i = 0; i<16; i++){
		air[i]->render(cameraX,cameraY);
  }
  if(dove!=NULL){
    dove->render(cameraX, cameraY);
		switch(dove->n_pipocas){
			case 0: status0->render(4,4);
							 break;
			case 1: status1->render(4,4);
					     break;
			case 2: status2->render(4,4);
							 break;
			case 3: status3->render(4,4);
					     break; 
    }
  }
  borus->render(cameraX, cameraY);
  


	for(vector<Obstaculo*>::iterator it = blocos.begin(); it != blocos.end(); it++){
	  Obstaculo *block = *it;
   // bloco->render(cameraX,cameraY);
    if((block->box.x > (cameraX - 100))&&(block->box.x<(cameraX + 800)))
    	block->render(cameraX,cameraY);
  }
  for(int i=0 ; i<NPIPOCAS; i++){

    if((pipocas[i]->box.x > (cameraX - 50))&&(pipocas[i]->box.x < (cameraX+800)) && (pipocas[i]->box.x!=0))
   	  pipocas[i]->render(cameraX,cameraY);
  }

  if((boomX!=0)&&(boomY!=0)){
    boom->render(boomX - cameraX, boomY - cameraY);
  }
  if((frangoX!=0)&&(frangoY!=0)){
    doveDepenado->render(frangoX - cameraX, frangoY - cameraY);
  }
  if(isPause)
		buttonPause->render(350,250);
  //}
 
}
    


void StateGame :: checkCollision(int dt){
 
  printf(" \n CHECK COLLISION \n");

  if((dove!=NULL)&&(borus!=NULL)){
     for(int i = 0; i<NPIPOCAS; i++)
		 {

				if(dove->collidesWith(pipocas[i])){
					dove->n_pipocas = dove->n_pipocas + 1;
          n_pipocas++;
					pipocas[i]->box.x = 0;
					//pipocas.erase(it);
          break;
        }
     }
		 for(int i = 0; i<16; i++)
     {
				if(dove->collidesWith(air[i])){
        	boomX = dove->box.x;
          boomY = dove->box.y;
          boom->update(dt);
          speedCamX = 0;
          music->stop();
				  sfx->play(1);
          if(dove->x >= SAVEP1){
          	saveStack = 1;
            if(dove->x >= SAVEP2)
              saveStack = 2;
          }
          
          delete dove;
          dove = NULL;

          return;
        }
		 }
					
     for(vector<Obstaculo*>::iterator it = blocos.begin(); it != blocos.end(); it++)
     {
        Obstaculo *bl1 = *it;
     
        if(dove->collidesWith(bl1)){
          boomX = dove->box.x;
          boomY = dove->box.y;
          boom->update(dt);
          speedCamX = 0;
          music->stop();
				  sfx->play(1);
          saveStack = 0;
          if(dove->x >= SAVEP1){
          	saveStack = 1;
            if(dove->x >= SAVEP2)
              saveStack = 2;
          }
          
          delete dove;
          dove = NULL;

          return;
       }

     }
     if(dove->collidesWith(borus)){
 				  boomX = dove->box.x;
          boomY = dove->box.y;
          boom->update(dt);
          speedCamX = 0;
          music->stop();
				  sfx->play(1);
					saveStack = 0;
          if(dove->x >= SAVEP1){
          	saveStack = 1;
            if(dove->x >= SAVEP2)
              saveStack = 2;
          }
          
          delete dove;
          dove = NULL;

          return;
     }
   }
  }

void StateGame :: pause(){
	music->pause();
  printf("\nENTER PAUSE\n");

	while((isPause)){
    processEvents();
		printf("\nisPause %d\n",isPause); 
		render();
	}
  printf("\nEXIT PAUSE\n");
}
