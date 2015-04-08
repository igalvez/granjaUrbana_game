#include "Obstaculo.h"


Obstaculo :: Obstaculo(Sprite *sprite, float x, float y, float w, float h):
	GameObject(x,y, 0, 0),
  sprite(sprite)
{
	
  box.w = w;
	box.h = h;
}

void Obstaculo :: render(float cameraX, float cameraY)
{
	sprite->render(box.x  - cameraX, box.y  - cameraY);
}

int Obstaculo :: update(int dt)
{
  
	return dt;

}

int Obstaculo :: update(int dt, float camx, float enemyX, float enemyY)
{
	return dt;
}
