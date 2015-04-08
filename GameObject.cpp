#include "GameObject.h"


GameObject :: GameObject(float x, float y, float w, float h)
{
  /*this->x = x;
  this->y = y;*/
  box.x = x;
  box.y = y;
  box.w = w;
  box.h = h;
}
    
bool GameObject :: collidesWith(GameObject *other)
{

  float diffx, diffy;

  diffx = box.x - other->box.x;// + cameraX;
  diffy = box.y - other->box.y;// - cameraY; 
  
  /*printf("\n diffx = %f diffy=%f\n", diffx, diffy);
  printf("\n ufo w = %f ufo h =%f  nave w = %f  nave h = %f\n", other->box.w, other->box.h, box.w, box.h);
  printf("\n ufo x = %f ufo y =%f  nave x = %f  nave y = %f\n", other->box.x, other->box.y, box.x, box.y);*/
 // printf("\n cam x = %f  cam y =%f \n", cameraX, cameraY);
  
  if((diffx > other->box.w)||(-diffx > box.w))
    return false;
  if((diffy > other->box.h)||(-diffy > box.h))
    return false;
  return true;
}
