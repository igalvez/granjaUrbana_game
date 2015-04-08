#include "Video.h" 


void Video :: DrawIMG(SDL_Surface *img, SDL_Surface *dest, int x, int y)
{
		SDL_Rect dest2;
		dest2.x = x;
		dest2.y = y;
		SDL_BlitSurface(img, NULL, dest, &dest2);
}

Video :: Video()
{
		MaxScaleX = MaxScaleY = MaxScale = 1;
		
		screen = 0;
		movieSurface = 0;
		movie = 0;
		X = Y = 0;
}

Video ::~Video()
{
		stop();
		SMPEG_delete( movie );
		movie = 0;
		SDL_FreeSurface( movieSurface );
		movieSurface = 0;
}
		
void Video :: clearScreen()
{
		SDL_FillRect(movieSurface, 0, 0);
}

void Video :: setVolume(int vol)
{
	SMPEG_setvolume(movie, vol);
}

void Video :: scale(int w, int h)
{
	if( w == 0 )
			w = 1;
		if( h == 0 )
			h = 1;

		SMPEG_scaleXY( movie, w, h );
		#ifdef _DEBUG
			CheckErrors();
		#endif
}

void Video :: scaleBy(int factor)
{
// Prevent a divide by 0
		if( factor == 0 )
			factor = 1;
		// Make sure we don't scale larger than the surface size
		if( factor > MaxScale )
			factor = MaxScale;

		SMPEG_scale( movie, factor );
		#ifdef _DEBUG
			CheckErrors();
		#endif
}

void Video :: setDisplayRegion(int x, int y, int w, int h)
{
		SMPEG_setdisplayregion( movie, x, y, w, h );
		#ifdef _DEBUG
			CheckErrors();
		#endif
}

void Video :: setPosition(int x, int y)
{
		X = x;
		Y = y;
}

void Video :: checkErrors()
{
		char* error = SMPEG_error( movie );
		if( error )
			printf( "Error: %s\n", error );
}

void Video :: load(const char* fileName, int maxscalex, int maxscaley)
{
	MaxScaleX = maxscalex;
	MaxScaleY = maxscaley;

	MaxScale = (maxscalex > maxscaley ? maxscaley : maxscalex);

	//screen = s; //verificar

	//Carrega o filme e armazena informacao sobre ele
	movie = SMPEG_new(fileName, &movieInfo, true);
 
  movieSurface = SDLBase::loadVideo(fileName, movieInfo.width * MaxScaleX,movieInfo.height * MaxScaleY,32);
  /*//Cria superficie temporaria para onde renderizar o video
	SDL_Surface *tempSurface2 = SDL_CreateRGBSurface(SDL_SWSURFACE, movieInfo.width * MaxScaleX, movieInfo.height * MaxScaleY, 32, screen->format->Rmask, screen->format->Gmask, screen->format->Bmask, screen->format->Amask);

	//Cria superficie otimizada para a tela principal
	movieSurface = SDL_DisplayFormat(tempSurface2);

	//Libera superficie temporaria
	SDL_FreeSurface(tempSurface2);*/

	//desenha na superficie
	SMPEG_setdisplay(movie, movieSurface, 0, 0);

	SMPEG_setdisplayregion(movie, 0, 0, movieInfo.width, movieInfo.height);
}

void Video :: setLoop(int val)
{
	SMPEG_loop(movie, val);
}

void Video :: play()
{
	SMPEG_play(movie);
}

void Video :: pause()
{
	SMPEG_pause(movie);
}

void Video :: stop()
{
	SMPEG_stop(movie);
}

void Video :: rewind()
{
	SMPEG_rewind(movie);
}

void Video :: seek(int bytes)
{
	SMPEG_seek(movie,bytes);
}

void Video :: skip(float seconds)
{
	SMPEG_skip(movie, seconds);
}

void Video :: renderFrame(int frame)
{
	SMPEG_renderFrame(movie, frame);
}

void Video :: renderFinal()
{
	SMPEG_renderFinal(movie, movieSurface, 0, 0);
}

void Video :: displayAt(int x, int y)
{
	DrawIMG(movieSurface, screen, x, y);
}

void Video :: display()
{
	SDLBase::movieDisplay(movieSurface, X, Y);
}

SMPEG_Info Video :: getInfo()
{
	SMPEG_getinfo(movie, &movieInfo);
	return movieInfo;
}

SMPEGstatus Video :: getStatus()
{
	return SMPEG_status(movie);

}
