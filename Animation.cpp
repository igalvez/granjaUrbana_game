#include "Animation.h"

Animation :: Animation(std::string filename, int frameTime, int n_sprites, bool repeat):
  Sprite(filename)
{
  printf("\n ENTRA EM ANIMATION LOAD \n");
  this->frameTime = frameTime;
  this->n_sprites = n_sprites;
  printf(" \n SURFACE %d \n",surface->w);
  clipRect.w = (surface->w)/n_sprites;
  clipRect.h = surface->h;
  clipRect.x = 0;//94;
  clipRect.y = 0;
  time = 0;
  this->repeat = repeat;
  printf("\n FIM ANIMATION LOAD \n");
}

bool Animation :: update(int dt)
{
  time += dt;
  if(frameTime>0){
  	frameSkip = time/frameTime;
  	time = time % frameTime;
 
		
 

  clipRect.x = clipRect.x + frameSkip * clipRect.w;
  
  
  if(clipRect.x >= surface->w)
  {

		clipRect.x = 0 ;// clipRect.x % surface->w;
   // clipRect.x = (clipRect.x - surface->w)%surface->w;
    
    if(!repeat){
     return false;
    }  
  }
 
    clip(clipRect.x, clipRect.y, clipRect.w, clipRect.h);
  }
    return true;
 
}

void Animation :: setFrame(int frame)
{
  clipRect.x = frame * clipRect.w;
  clip(clipRect.x, clipRect.y, clipRect.w, clipRect.h);
}

void Animation :: setFrameTime(int time)
{
  frameTime = time;
}

int Animation :: getframeTime()
{
  return frameTime;
}
