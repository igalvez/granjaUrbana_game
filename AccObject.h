#include "GameObject.h"
#include "Animation.h"

#ifndef ACCOBJECT_H
#define ACCOBJECT_H

class AccObject : public GameObject{
  private:
    Animation *animation;
    Animation *turn;
    int turning;
    float speed;
    float acceleration;
    float rotation;
    double vx, vy, ax, ay;
  public:
    AccObject(Animation *animation,float x, float y, int hitPoints);
    int hitPoints;
    void render(float cameraX, float cameraY);
    int update(int dt);
};

#endif
  
