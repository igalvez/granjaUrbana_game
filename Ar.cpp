#include "Ar.h"

#define XBOXO 0
#define WBOXO 174
#define YBOXO 27
#define HBOXO 136

Ar :: Ar(Sprite *sprite, float x, float y):
	GameObject(x,y, 0, 0),
  sprite(sprite)
{
	this->x = x;
	this->y = y;
	box.x = x + XBOXO;
	box.y = y + YBOXO;
  box.w = WBOXO;
	box.h = HBOXO;
}

void Ar :: render(float cameraX, float cameraY)
{
	sprite->render(x  - cameraX, y  - cameraY);
}

int Ar :: update(int dt)
{
  
	return dt;

}

int Ar :: update(int dt, float camx, float enemyX, float enemyY)
{
	return dt;
}
