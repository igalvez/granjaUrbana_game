#include "SDLBase.h"
#include <smpeg/smpeg.h>


#ifndef VIDEO_H
#define VIDEO_H

class Video {
	private:
		// Surface for the main screen
		SDL_Surface *screen;

		// Surface for the movie
		SDL_Surface *movieSurface;

		// Holds the movie information
		SMPEG_Info movieInfo;

		// Load the movie
		SMPEG *movie;

		// The max we can scale by
		int MaxScaleX;
		int MaxScaleY;
		int MaxScale;

		// Locations on screen to draw at
		int X, Y;
    void DrawIMG(SDL_Surface *img, SDL_Surface *dest, int x, int y);

	public:
		Video();
		~Video();
		void clearScreen();
		void setVolume(int vol);
		void scale(int w, int h);
		void scaleBy(int factor);
		void setDisplayRegion(int x, int y, int w, int h);
		void setPosition(int x, int y);
		void checkErrors();
		void load(const char* fileName, int maxscalex = 1, int maxscaley = 1);
		void setLoop(int val);
		void play();
		void pause();
		void stop();
		void rewind();
		void seek(int bytes);
		void skip(float seconds);
		void renderFrame(int frame);
		void renderFinal();
		void displayAt(int x, int y);
		void display();
		SMPEG_Info getInfo();
		SMPEGstatus getStatus();
};

#endif
