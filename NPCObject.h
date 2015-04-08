#include "GameObject.h"
#include "Animation.h"
#include "InputManager.h"

#ifndef NPCOBJECT_H
#define NPCOBJECT_H
#define SPEEDBORUSX 0.9
//#define SPEEDY 0.2

class NPCObject : public GameObject {
   private:
      Animation *animation;
      
      float acceleration;
      double vx, vy, ax, ay;
   public:
			float teta;
      float speedx,speedy;
 			float x, y;
      NPCObject(Animation *animation,float x, float y);
      void render(float cameraX, float cameraY);
      int update(int dt);
      int onAttack;
      int update(int dt, float camx, float enemyX, float enemyY); //,float enemyX, float enemyY, float cameraX, float cameraY );
      void attack(float enemyX, float enemyY);
      void retorna(float camx);

};
#endif
