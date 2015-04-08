#include "GameObject.h"
#include "Sprite.h"

#ifndef AR_H
#define AR_H

class Ar : public GameObject{
	private:
		Sprite *sprite;
	public:
    float x, y;
		Ar(Sprite *sprite,float x, float y);
  	void render(float cameraX, float cameraY);
    int update(int dt, float camx, float enemyX, float enemyY);
  	int update(int dt);
};

#endif

