#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "SDLBase.h"
#include <cmath>
#include <SDL/SDL_rotozoom.h>
#include "Video.h"


using namespace std;

SDL_Surface* SDLBase::screen = NULL;

SDLBase :: ~SDLBase()
{
	TTF_Quit();
	SDL_FreeSurface(screen);
}

void SDLBase :: inicializaSDL() {
   SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER);
   screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
   SDL_WM_SetCaption("Trabalho 4 - 0944475", "Trabalho 4");
   TTF_Init(); // Inicializa Biblioteca TTF
	 Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
}

SDL_Surface* SDLBase :: getScreen() {
  return screen;
}

SDL_Surface* SDLBase :: loadImage(string arquivo){
  SDL_Surface *surface = 0;
  SDL_Surface *newSurface = 0;
  printf("\n SDLBASE LOADIMAGE ENTRA %s\n",arquivo.c_str());
  surface = IMG_Load(arquivo.c_str());
  printf("\n ARQUIVO CARREGADO\n");
  if(surface->format->Amask){
    printf("\n AMASK \n");
    newSurface = SDL_DisplayFormatAlpha(surface);
    printf("\n FIM AMASK \n");
  }
  else {
		 printf("\n NOAMASK\n");
     newSurface = SDL_DisplayFormat(surface);
		 printf("\n FIM NOAMASK\n");
  }
  SDL_FreeSurface(surface);
  return newSurface;
}

void SDLBase :: renderSurface(SDL_Surface* surface, SDL_Rect* clip, SDL_Rect* dst){
  SDL_BlitSurface(surface, clip, screen, dst);
}

void SDLBase :: atualizarTela(){
  SDL_Flip(screen);
}

void SDLBase::drawLine(int x1, int y1, int x2, int y2, int rgb, int spacing)
{
	int deltax = abs(x2 - x1); // The difference between the x's
	int deltay = abs(y2 - y1); // The difference between the y's
	int x = x1;                // Start x off at the first pixel
	int y = y1;                // Start y off at the first pixel
	int xinc1 = 0;
	int yinc1 = 0;
	int xinc2 = 0;
	int yinc2 = 0;
	int den = 0;
	int num = 0;
	int numadd = 0;
	int numpixels = 0;

	if (x2 >= x1)              // The x-values are increasing
	{
		xinc1 = 1;
		xinc2 = 1;
	}
	else                       // The x-values are decreasing
	{
		xinc1 = -1;
		xinc2 = -1;
	}

	if (y2 >= y1)              // The y-values are increasing
	{
		yinc1 = 1;
		yinc2 = 1;
	}
	else                       // The y-values are decreasing
	{
		yinc1 = -1;
		yinc2 = -1;
	}

	if (deltax >= deltay)		// There is at least one x-value for every y-value
	{
		xinc1 = 0;				// Don't change the x when numerator >= denominator
		yinc2 = 0;				// Don't change the y for every iteration
		den = deltax;
		num = deltax / 2;
		numadd = deltay;
		numpixels = deltax;		// There are more x-values than y-values
	}
	else						// There is at least one y-value for every x-value
	{
		xinc2 = 0;				// Don't change the x for every iteration
		yinc1 = 0;				// Don't change the y when numerator >= denominator
		den = deltay;
		num = deltay / 2;
		numadd = deltax;
		numpixels = deltay;		// There are more y-values than x-values
	}

	for (int curpixel = 1; curpixel <= numpixels; curpixel++)
	{
		if (spacing == 0)
		{
			SDL_Rect pixel = {x,y,1,1};
			SDL_FillRect(screen,&pixel,rgb);
		}
		else if (curpixel % spacing >= spacing/2)
		{
			SDL_Rect pixel = {x,y,1,1};
			SDL_FillRect(screen,&pixel,rgb);
		}

		num += numadd;         // Increase the numerator by the top of the fraction
		if (num >= den)        // Check if numerator >= denominator
		{
			num -= den;         // Calculate the new numerator value
			x += xinc1;         // Change the x as appropriate
			y += yinc1;         // Change the y as appropriate
		}
		x += xinc2;             // Change the x as appropriate
		y += yinc2;             // Change the y as appropriate
	}
}
  
SDL_Surface* SDLBase :: clip(SDL_Surface *original, SDL_Rect *clip)
{
  SDL_Surface *novaSurface;

  if((original!=NULL)&&(clip->h>=0)&&(clip->w>=0)){
    novaSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, clip->w, clip->h, 32, 0, 0, 0, 0);
    SDL_BlitSurface(original,clip,novaSurface,NULL);
    return novaSurface;
  }
  else
    return NULL; 
}
SDL_Surface* SDLBase :: rotoZoom(SDL_Surface *surface, float angle, float zoom)
{
  SDL_Surface *rotate;
  if((surface!=NULL)){
    rotate = rotozoomSurface(surface, (double)angle, zoom, 1);
    return rotate;
  }
  else{
    return NULL;
    
  }
}

SDL_Surface* SDLBase ::  loadVideo(const char* fileName, int width, int height, int depth)
{
	SDL_Surface *movieSurface = 0;

	SDL_Surface *tempSurface2 = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, depth, screen->format->Rmask, screen->format->Gmask, screen->format->Bmask, screen->format->Amask);

	//Cria superficie otimizada para a tela principal
	movieSurface = SDL_DisplayFormat(tempSurface2);

	//Libera superficie temporaria
	SDL_FreeSurface(tempSurface2);
  return movieSurface;
}

void SDLBase :: movieDisplay(SDL_Surface* movieSurface, int x, int y)
{
	DrawIMG(movieSurface, screen, x, y);
SDL_Flip( screen );
}

void SDLBase :: DrawIMG(SDL_Surface *img, SDL_Surface *dest, int x, int y)
{
		SDL_Rect dest2;
		dest2.x = x;
		dest2.y = y;
		SDL_BlitSurface(img, NULL, dest, &dest2);
}
