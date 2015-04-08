#include "Sprite.h"
#include "GameObject.h"

#ifndef PLANET_H
#define PLANET_H

class Planet : public GameObject{
  protected:
    int hitPoints; 
  public:
    Sprite *sprite;
    Planet(Sprite *sprite, float x, float y, float w, float h, int hitPoints);
    virtual int update(int dt) = 0;
    void render(float cameraX, float cameraY);
    int getHitpoints();
    float atualizaX(float vx);
    float atualizaY(float vy);
    float getX();
    float getY();

};

#endif
  
