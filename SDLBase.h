#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
//#include <SDL/SDL_rotozoom.h>


#ifndef SDLBASE_H
#define SDLBASE_H
using namespace std;

class SDLBase{
  private:
    static SDL_Surface *screen;
  public:
    ~SDLBase();
    static void inicializaSDL();
    static SDL_Surface* clip(SDL_Surface *original, SDL_Rect *clip);
    static SDL_Surface* rotoZoom(SDL_Surface *surface, float angle, float zoom=1.0f);
    static SDL_Surface* getScreen();
    static SDL_Surface* loadImage(string arquivo);
    static SDL_Surface* loadVideo(const char* fileName, int width, int height, int depth);
		static void movieDisplay(SDL_Surface* movieSurface, int x, int y);
    static void renderSurface(SDL_Surface *surface, SDL_Rect *clip, SDL_Rect *dst);
    static void atualizarTela();
    static void drawLine(int x1, int y1, int x2, int y2, int rgb, int spacing);
    static void DrawIMG(SDL_Surface *img, SDL_Surface *dest, int x, int y);
};

#endif




