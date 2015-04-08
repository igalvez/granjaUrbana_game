#include "Planet.h"

Planet :: Planet(Sprite *sprite, float x, float y, float w, float h, int hitPoints):
  GameObject(x,y,w,h),
  sprite(sprite)
{
   this->hitPoints = hitPoints;



  /*O construtor da classe. Deve chamar o construtor da classe pai (passando os
    valores de x e y) e inicializar o valor de hitPoints e da sprite.*/

}

void Planet :: render(float cameraX, float cameraY)
{
  /*Se a sprite nao for nula, mostra na tela (levando em consideração os valores
    da câmera).*/
  sprite->render(box.x - cameraX, box.y - cameraY);

}

int Planet :: getHitpoints(){

  return hitPoints;
  
}

float Planet :: getX(){
  return box.x;
}

float Planet :: getY(){
  return box.y;
}
float Planet :: atualizaX(float vx){
  box.x = box.x + vx;
  return box.x;
}
  
float Planet :: atualizaY(float vy)
{
  box.y = box.y + vy;
  return box.y;
}
