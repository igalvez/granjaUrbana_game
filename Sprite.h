#include "SDLBase.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>

#ifndef SPRITE_H
#define SPRITE_H
class Sprite {
  protected:
    SDL_Surface *surface;
    SDL_Surface *surfaceRotoZoom;
    float angle;
    float zoom;
    SDL_Rect clipRect;
  public:
    Sprite(string arquivo);
    ~Sprite();
    void load(string arquivo);
    void clip(int x, int y, int w, int h);
    //virtual void update(int dt);
    SDL_Surface* rotoZoom(float angle, float zoom=1.0f, bool force=false);
    void restore();
    SDL_Rect getClip();
    void render(int x, int y);
    int getWidth();
    int getHeight();
};

#endif
