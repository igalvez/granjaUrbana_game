#include "FollowerObject.h"
#include <queue>
#include <cmath>

using namespace std;

FollowerObject::FollowerObject(Sprite *sprite, float x, float y, float w, float h):
  GameObject(x,y,w,h),
  sprite(sprite)

{  x1 = -4000;
   y1 = -4000;
}

int FollowerObject::update(int dt)
{
  float cx,cy;
  const float c =0.3;
  /*Atualizando coordenada x*/
  if((coordinateXQueue.size()!=0)){
    if((x1==-4000)&&(y1==-4000)){
      cx = coordinateXQueue.front();
      cy = coordinateYQueue.front();
      y1 = box.y;
      x1 = box.x;
      z = sqrt(pow(box.x-cx,2) + pow(box.y-cy,2));
      
    }
    speedX = c*dt*((coordinateXQueue.front()-x1)/z);
    speedY = c*dt*((coordinateYQueue.front()-y1)/z);
    if(x1!=-4000){
      if(coordinateXQueue.front()>x1){
        if(coordinateXQueue.front()>(box.x+speedX)){
          box.x = box.x + speedX;
        }
        else{
          box.x = coordinateXQueue.front();
          coordinateXQueue.pop();
          x1 = -4000;
        }
      }
      else{
        if(coordinateXQueue.front()<(box.x+speedX)){
          box.x = box.x + speedX;
        }
        else{
           box.x = coordinateXQueue.front();
           coordinateXQueue.pop();
           x1 = -4000;
        }
      }
     }
     
     if(y1!=-4000){
        if(coordinateYQueue.front()>y1){
          if(coordinateYQueue.front()>(box.y+speedY)){
            box.y = box.y + speedY;
          }
          else{
            box.y = coordinateYQueue.front();
            coordinateYQueue.pop();
            y1 = -4000;
          }
        }
        else{
          if(coordinateYQueue.front()<(box.y+speedY)){
            box.y = box.y + speedY;
          }
          else{
             box.y = coordinateYQueue.front();
             coordinateYQueue.pop();
             y1 = -4000;
          }
        }
     }
   }
   return 0;
}
  

    
void FollowerObject::render(float cameraX, float cameraY)
{
  /*Renderiza o objeto pelo centro. Ou seja, caso o objeto esteja em (0,0)
    seu centro deve estar nessa posição, e não o canto superior esquerdo da
    imagem.*/

  sprite->render(box.x - cameraX - 16 , box.y - cameraY - 16);
}
 
void FollowerObject::renderQueueLines(float cameraX, float cameraY)
{
  /*
    Este método deve mostrar na tela linhas que correspondem aos comandos
    enfileirados (caso haja algum). Para isso, deve ser usado o método
    SDLBase::drawLine, fornecido nos arquivos do laboratório.
    Dica: Não é possível iterar na fila! Para acessar todos os elementos da fila
    será necessário removê-los e colocá-los em uma fila auxiliar, um a um. Uma boa
    estratégia é remover os elementos, renderizá-los, e inserí-los em uma lista auxiliar
    e, por fim, atribuir essa lista de volta para a original.
  */
    
  std::queue<float> auxX;
  std::queue<float> auxY;
  float x2,y2;
  int tamanho;
  
  auxX = coordinateXQueue;
  auxY = coordinateYQueue;
  
  
  tamanho = auxX.size();
  x2 = box.x;
  y2 = box.y;
  while(auxX.size()>0){
    for(int i = 0; i<tamanho; i++){
      SDLBase::drawLine(x2-cameraX,y2-cameraY,auxX.front()-cameraX,auxY.front()-cameraY,4294967294,2);
      x2 = auxX.front();
      y2 = auxY.front();
      auxX.pop();
      auxY.pop();
    }
  }
}

void FollowerObject::enqueuedCommand(float posX, float posY)
{
/*Coloca a posição pos na fila. Alternativamente, pode-se usar 2 listas, uma
para X e outra para Y, e passar ambos os parâmetros como argumento.*/
  coordinateXQueue.push(posX);
  coordinateYQueue.push(posY);

}
