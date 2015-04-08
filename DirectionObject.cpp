#include "DirectionObject.h"
#define XBOXD 20
#define WBOXD 68
#define YBOXD 33
#define HBOXD 33

DirectionObject :: DirectionObject(Animation *animation,float x, float y):
  GameObject(x,y, 0, 0),
  animation(animation)
{
  speedx = 0;
  speedy = 0;
  accelerationX = 0;
	accelerationY = 0;
  this->x = x;
  this->y = y;
  box.x = x + XBOXD;
  box.y = y + YBOXD;
  box.w = WBOXD;
  box.h = HBOXD;
  n_pipocas = 0;
  boost = 0;
	sound = 0;
	sfxBoost = new Audio("sound/PomboBoost0.wav",0);
  //box.x =;
}
	
void DirectionObject :: render(float cameraX, float cameraY)
{
  animation->render(x - cameraX, y - cameraY );
  
}

int DirectionObject :: update(int dt)
{
   
  /*Verificando se w ou s foram pressionadas (sentido vertical) */
   //int boost = 0;
   accelerationX = 0.00002*dt;
   accelerationY = 0.00003*dt;

   if((InputManager::getInstance()->iskeyDown(SDLK_SPACE))){
			if(n_pipocas>0){
				n_pipocas --;
				sfxBoost->play(1);
        boost = 1;
				sound = 1;
				speedx = 0.2;
				
      }
 				
   }
   if(boost == 1){
      cont++;
      animation->setFrameTime(28);
		
      if(cont>=80){
		    boost = 0;
				cont = 0;
				speedx = 0;
				animation->setFrameTime(50);
      }
 
   }

   if((InputManager::getInstance()->isKeyPressed(SDLK_DOWN))){
        // acceleration = 0.00001*dt; 
         speedy += accelerationY * dt;
         if(boost ==0)
         	animation->setFrameTime(70);
          
        //speedy = SPEEDY;
          printf("\n VELOCIDADE y %f\n",speedy);
    }
    else{
			if(speedy>0){
				speedy -= DESACELERA;
        if(speedy<0)
					speedy = 0;
      }
    }
      	
    if((InputManager::getInstance()->isKeyPressed(SDLK_UP))){
         speedy -= accelerationY * dt;
         if(boost == 0);
           animation->setFrameTime(35);
         //acceleration = 0.00001*dt; 
         //speedy = -SPEEDY;
				 
         
    }
    else{
			if(speedy<0){
				speedy += DESACELERA;
        if(speedy>0)
					speedy = 0;
      }
    }
    if((InputManager::getInstance()->iskeyUp(SDLK_DOWN))){
        // acceleration = 0.00001*dt; 
				if(boost==0)
         animation->setFrameTime(50);
    }
    if((InputManager::getInstance()->iskeyUp(SDLK_UP))){

         //acceleration = 0.00001*dt; 
				if(boost ==0)
         animation->setFrameTime(50);
    }
   
		if((InputManager::getInstance()->isKeyPressed(SDLK_RIGHT))){

         //acceleration = 0.00001*dt; 
         if(boost==0){
         	speedx += accelerationX*dt;
         	animation->setFrameTime(35);
         }
				 
    }    
    if((InputManager::getInstance()->isKeyPressed(SDLK_LEFT))){

         //acceleration = 0.00001*dt; 
         if(boost == 0){
        	 speedx -= accelerationY*dt;
        	 animation->setFrameTime(70);
         }
				 
    }
    if((InputManager::getInstance()->iskeyUp(SDLK_RIGHT))){
        // acceleration = 0.00001*dt; 
         speedx= 0;
         animation->setFrameTime(50);
    }
    if((InputManager::getInstance()->iskeyUp(SDLK_LEFT))){

         //acceleration = 0.00001*dt; 
         speedx = 0;
         animation->setFrameTime(50);
    }
 
    if(speedy > SPEEDYMAX)
			speedy = SPEEDYMAX;
    else if(speedy < -SPEEDYMAX)
			speedy = -SPEEDYMAX;
    if(boost == 0){
    	if(speedx > SPEEDX)
     		speedx = SPEEDX;
    	else if(speedx< -SPEEDX)
				speedx = -SPEEDX;
    }
    //if((((box.x + speedx*dt)< (cameraX + 700)))&&((box.x + speedx*dt)>(cameraX + 200))){
    	x += speedx*dt;

    //}
   if((((box.y + speedy*dt)<520))&&((box.y + speedy*dt)>0)){
   	  y += speedy*dt; 
    }
    box.x = x + XBOXD;
    box.y = y + YBOXD;
    animation->update(dt); 
    
    return boost;
    
}


int DirectionObject :: update(int dt, float camx, float enemyX, float enemyY)
{
  return dt;
}
