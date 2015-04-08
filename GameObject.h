#include "SDLBase.h"
#include "Rect.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject{
 // protected:
    
  public:
   /* float x;
    float y;*/
    Rect box;
    GameObject(float x, float y, float w, float h);
    bool collidesWith(GameObject *other);
    virtual int update(int dt) = 0;
    virtual int update(int dt, float camx, float enemyX, float enemyY) = 0;
    virtual void render(float cameraX, float cameraY) = 0;
};


#endif
