#include "Sprite.h"
#include "SDLBase.h"
#include <string>


#ifndef ANIMATION_H
#define ANIMATION_H

class Animation : public Sprite{
  private:
    int n_sprites;
    int time;
    int frameSkip;
    int frameTime;
    bool repeat;
    SDL_Rect animRect;
  public:
    Animation(std::string filename, int frameTime, int n_sprites, bool repeat);
    bool update(int dt);
    void setFrame(int frame);
    void setFrameTime(int time);
    void renderTurn(float camX, float camY);
    int getframeTime();
};

#endif
