#include "AccObject.h"
#include <cmath>
#include "InputManager.h"

#define V_MAX 100.0f
#define ATRITO 0.001f

AccObject :: AccObject(Animation *animation, float x, float y, int hitPoints):
  GameObject(x,y, 0, 0),
  animation(animation),
  hitPoints(hitPoints)
{
  //this->hitPoints = hitPoints;
  turn = new Animation("NaveTurnSheet.png",94,4,true);
  rotation = 0;
  speed = 0;
  acceleration = 0;
  turning = -1;
  box.w = animation->getClip().w;
  box.h = animation->getClip().h;

  
}

void AccObject :: render(float cameraX, float cameraY)
{
  if(turning==-1){
    animation->render(box.x - cameraX, box.y - cameraY );
  }
  else{
    turn->render(box.x - cameraX, box.y - cameraY);
  }
}

int AccObject :: update(int dt)
{
    turning = -1;
    acceleration = 0;
  /* Verificando se a ou d foram pressionadas (sentido horizontal)*/
    if((InputManager::getInstance()->isKeyPressed(SDLK_d))){
      rotation = rotation - dt/10;
      turning = 3;
      //v=c*dt;
      printf("\nROTATION %f\n", rotation);
    }
    if((InputManager::getInstance()->isKeyPressed(SDLK_a))){
      rotation = rotation + dt/10;
      turning = 0;
      //v=c*dt;
      printf("\nROTATION %f\n", rotation);
    }
  /*Verificando se w ou s foram pressionadas (sentido vertical) */
 
    if((InputManager::getInstance()->isKeyPressed(SDLK_s))){

      
      if(speed > -V_MAX){
         acceleration = 0.00001*dt; 
         speed += acceleration * dt;
         animation->setFrameTime(300);
      }
      if(speed < -V_MAX)
         speed = -V_MAX;
    }
    if((InputManager::getInstance()->isKeyPressed(SDLK_w))){

       
       if(speed < V_MAX){
         acceleration = 0.00001*dt; 
         speed -= acceleration * dt;
         animation->setFrameTime(50);
       }
       if(speed > V_MAX)
         speed = V_MAX;
     /* printf("\nROTATION %f\n", rotation);
      printf("\nV %f\n", speed);
      printf("\nVx %f\n", vx);
      printf("\nVy %f\n", vy);
       printf("\nax %f\n", acceleration);
      printf("\nay %f\n", aux);
       printf("\ndt %d\n", dt);*/
    }
    if((InputManager::getInstance()->iskeyUp(SDLK_w))||(InputManager::getInstance()->iskeyUp(SDLK_s)))
      animation->setFrameTime(200);
    if((acceleration == 0)&&(speed!=0)){
      if((speed > 0)&&(speed - ATRITO>0))
        speed -= ATRITO;
      else if((speed<0)&&(speed + ATRITO<0))
        speed += ATRITO;
      else
        speed = 0;
    }
    
    box.x += speed * cos((rotation - 90) * (M_PI/180))*dt;
    box.y += speed * (-sin((rotation-90) * (M_PI/180)))*dt;
  /*Atualizando posicoes x e y */
  // printf("\n X = %f Y=%f\n",x,y);
  if(turning!=-1){  
    turn->setFrame(turning);
    turn->rotoZoom(rotation);
  }
  animation->update(dt); 
  animation->rotoZoom(rotation);
  return dt;
}
