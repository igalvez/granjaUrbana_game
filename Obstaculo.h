#include "GameObject.h"
#include "Sprite.h"

#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo : public GameObject{
	private:
		Sprite *sprite;
	public:
    float x, y;
		Obstaculo(Sprite *sprite,float x, float y, float w, float h);
  	void render(float cameraX, float cameraY);
    int update(int dt, float camx, float enemyX, float enemyY);
  	int update(int dt);
};

#endif

