#include "SDLBase.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifndef TEXT_H
#define TEXT_H

class Text{
	private:
		static const SDL_Color colorDefault;
		TTF_Font *font;
		SDL_Surface *textSurface;
		string fontFile;
		string text;
		int style;
		int ptsize;
		SDL_Color color;
		SDL_Rect box;
	public:
		Text(string fontFile, string text, int x=0, int y=0, int ptsize = 10, int style = 0, SDL_Color color = colorDefault);
		~Text();
		void render(int cameraX = 0 , int cameraY = 0);
		void setPos(int x, int y);
		void setText(string text);
		void setColor(SDL_Color color);
		void setStyle(int style);
		void setSize(int ptsize);
};

#endif
