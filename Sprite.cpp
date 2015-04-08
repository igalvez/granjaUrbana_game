#include "Sprite.h"
#include <string>
using namespace std;


Sprite :: Sprite(string arquivo){
  printf("\n ENTRA SPRITE \n");
  surface = NULL;
  surfaceRotoZoom = NULL;
  angle = 0;
  zoom = 1.0;
  printf("\n ARQUIVO %s\n",arquivo.c_str());
  load(arquivo);
  printf("\n ARQUIVO LOADED%s\n",arquivo.c_str());
  printf("\n SAI SPRITE \n");
}
Sprite :: ~Sprite(){
  if(surface!=NULL)
    SDL_FreeSurface(surface);
  if(surfaceRotoZoom!=NULL)
    SDL_FreeSurface(surfaceRotoZoom);
}

void Sprite :: load(string arquivo){
  if(surface!=NULL){
    SDL_FreeSurface(surface);
  }
  surface = SDLBase::loadImage(arquivo);/*arquivo.c_str()*/
  clipRect.x = 0;
  clipRect.y = 0;
  clipRect.w = surface->w;
  clipRect.h = surface->h;
}

void Sprite :: clip(int x, int y, int w, int h){
  clipRect.x = x;
  clipRect.y = y;
  clipRect.w = w;
  clipRect.h = h;
  if(surfaceRotoZoom!=NULL){
    rotoZoom(angle, zoom, true);
  }
}

SDL_Rect Sprite :: getClip(){
  return clipRect;
}

void Sprite :: render(int x, int y){
  SDL_Rect dst;
  float difX, difY;
  SDL_Rect aux;
  
  /*.w=0;
  dst.h=0;*/
  if(surfaceRotoZoom != NULL){
    difX = (clipRect.w)/2 - (surfaceRotoZoom->clip_rect.w)/2;
    difY = (clipRect.h)/2 - (surfaceRotoZoom->clip_rect.h)/2;
    dst.x = x + difX;
    dst.y = y + difY;
    printf("\n x = %d  y = %d w=%d h=%d\n",surfaceRotoZoom->clip_rect.x,surfaceRotoZoom->clip_rect.y,surfaceRotoZoom->clip_rect.w,surfaceRotoZoom->clip_rect.h);
    
    aux=surfaceRotoZoom->clip_rect;
    SDLBase::renderSurface(surfaceRotoZoom, &aux, &dst);
  }
  else{
    /*ARRUMAR*/
    dst.x = x;
    dst.y = y;
    SDLBase::renderSurface(surface, &clipRect, &dst);
  }
}

int Sprite :: getWidth(){
  if(surfaceRotoZoom!=NULL)
    return surfaceRotoZoom->w;
  return surface->w;
}

int Sprite :: getHeight(){
  if(surfaceRotoZoom!=NULL)
    return surfaceRotoZoom->h;
  return surface->h;
}

SDL_Surface* Sprite :: rotoZoom(float angle, float zoom, bool force)
{
  SDL_Rect rectAux;
  SDL_Surface *aux;
  
  if((this->angle!=angle)||(this->zoom!=zoom)||(force==true)){
    restore();
    this->angle = angle;
    this->zoom = zoom;
  // if((clipRect.w!=surface->w)||(clipRect.h!=surface->h)||(clipRect.x !=0)||(clipRect.y != 0))
   //{
   printf("\n 1 \n");
      rectAux = clipRect;
      printf("\nRECTAUX x=%d y=%d w=%d h=%d\n",rectAux.x,rectAux.y,rectAux.w,rectAux.h);
      aux = SDLBase::clip(surface, &rectAux);
    //}
      surfaceRotoZoom = SDLBase::rotoZoom(aux, angle, zoom);
      SDL_FreeSurface(aux);
    printf("\n 2 \n");
    printf("\nCLIPRECT x=%d y=%d w=%d h=%d\n",clipRect.x,clipRect.y,clipRect.w,clipRect.h);
    printf("\nsurface rotozoom x=%d y=%d\n",surfaceRotoZoom->w, surfaceRotoZoom->h);
    if(surfaceRotoZoom==NULL)
      printf("\nSURFACE NULA \n");
    return surfaceRotoZoom;
  }
  else
    return NULL;
      
    
}

void Sprite :: restore()
{
  SDL_FreeSurface(surfaceRotoZoom);
}

