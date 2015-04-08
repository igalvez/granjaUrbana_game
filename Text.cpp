#include "Text.h"

using namespace std;

const SDL_Color Text::colorDefault = {255,255,255,255};

Text :: Text(string fontFile, string text, int x, int y, int ptsize, int style, SDL_Color color)
{
  /* Setando variaveis */
	
	this->fontFile = fontFile;
	this->text = text;
	this->ptsize = ptsize;
	this->style = style;
	this->color = color;
  box.x = x;
	box.y = y;

	/*Configurando nova fonte */
	font = TTF_OpenFont(fontFile.c_str(), ptsize); // Abre uma fonte TTF
  if(font==NULL){
		printf("\n NULO ");
  }
  else{
		TTF_SetFontStyle(font, style); // Define o stilo da fonte
  }
	textSurface = TTF_RenderText_Solid(font, text.c_str(), color); //Surface com a cor e tipo de fonte escolhidos
	
}

Text :: ~Text()
{
	TTF_CloseFont(font);
	SDL_FreeSurface(textSurface);
}
	
void Text :: render(int cameraX, int cameraY)
{
	SDL_Rect dest;
	SDL_Rect clipRect; 
	dest.x = box.x;
  dest.y = box.y;
 
	clipRect = textSurface->clip_rect;
  SDLBase::renderSurface(textSurface, &clipRect, &dest);

}

void Text :: setPos(int x, int y)
{
	box.x = x;
	box.y = y;
}

void Text :: setText(string text)
{
	this->text = text;
}

void Text :: setColor(SDL_Color color)
{
	this->color = color;
}

void Text :: setStyle(int style)
{
	this->style = style;
}
		
void Text :: setSize(int ptsize)
{
	this->ptsize = ptsize;
}
