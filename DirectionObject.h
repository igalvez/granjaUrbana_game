#include "GameObject.h"
#include "Animation.h"
#include "Audio.h"
#include "InputManager.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef DIRECTIONOBJECT_H
#define DIRECTIONOBJECT_H

#define SPEEDX 0.1f
#define SPEEDYMAX 0.45f
#define SPEEDY 0.5f
#define DESACELERA 0.02f

class DirectionObject : public GameObject {
   private:
      Animation *animation;
			Audio *sfxBoost;
      //float speedx,speedy;
      float accelerationX, accelerationY;
      double vx, vy, ax, ay;
      int boost;
      int cont;
   public:
      float speedx,speedy;
      float x, y;
      int sound;
      int n_pipocas;
      DirectionObject(Animation *animation,float x, float y);
      void render(float cameraX, float cameraY);
      int update(int dt, float camx, float enemyX, float enemyY);
      int update(int dt);

};

#endif
