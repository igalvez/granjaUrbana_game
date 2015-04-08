#include "NPCObject.h"
#include <cmath>


#define XBOXN 42
#define WBOXN 126
#define YBOXN 80
#define HBOXN 30

#define SPEEDYB 5.0f

#define SPEEDTOTAL 1.2f

NPCObject :: NPCObject(Animation *animation,float x, float y):
GameObject(x,y, 0, 0),
animation(animation)
{
  box.x = x + XBOXN;
	box.y = y + YBOXN;
  box.w = WBOXN;
  box.h = HBOXN;
	this->x = x;
	this->y = y;
  speedx = 0;
  speedy = 0;
  onAttack = 0;
  teta = 0;
}
      
void NPCObject :: render(float cameraX, float cameraY)
{
  animation->render(x - cameraX, y - cameraY );
}


int NPCObject :: update(int dt)
{
  return dt;
}

int NPCObject :: update(int dt, float camx, float enemyX, float enemyY) 
{
   
   // box.x += speedx*dt;

    //if(box.x > 600)
    if(((enemyX > 17000)&&(enemyX < 23000))||((enemyX > 45000)&&(enemyX < 60000))){
			attack(enemyX, enemyY);
      onAttack = 1;
    }
    else{
    	if(onAttack == 1)
				retorna(camx);
    
    }
		//attack(enemyX,enemyY,dt);
   // box.x+= speedx*dt;
    if(enemyY > (y)){
     speedy = 0.1;
     y += speedy*dt; 
     if((y) > enemyY)
       y = enemyY;
     printf(" \n dove mais baixo q borus \n");
     
   }
   else if(enemyY < box.y){
     speedy = -0.1;
     y += speedy*dt; 
     if(y < enemyY)
       y = enemyY;
     printf(" \n dove mais alto q borus \n");
   }
   else{
     speedy = 0;
     printf(" \n dove e borus na msma altura \n");
   }
     
   /*if(onAttack){
		if(speedy == 0.1)
			speedy = 0.67;
   }*/
    animation->update(dt); 
		box.x = x + XBOXN;
		box.y = y + YBOXN;
    return dt;
}


void NPCObject :: attack(float enemyX, float enemyY)
{

  
  if(enemyX > x + box.w/2){
		speedx += 0.002;
		if(speedx > 0.07){
			speedx = 0.07;
      //if(speedy>0)		
    }
    animation->setFrameTime(40);
  }
  else if(enemyX < x){
		speedx = -0.07;
		animation->setFrameTime(60);
  }
  else
    speedx = 0;
	/*if(enemyX > (box.x + box.w)){	
		speedx = 0.5;
  }
  else
		speedx = 0;
  box.x -= speedx*dt;*/
}

void NPCObject :: retorna(float camx)
{
  //onAttack = 0;
	if(box.x > camx ){
		speedx = -0.05;
    animation->setFrameTime(80);
	}
	else {	
		speedx = 0;
    onAttack = 0;
    animation->setFrameTime(60);
  }
}
