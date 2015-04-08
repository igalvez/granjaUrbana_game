#include <string>
#include <SDL/SDL_mixer.h>

#ifndef AUDIO_H
#define AUDIO_H

class Audio {
	private:
		std::string fileName;
		Mix_Chunk *sound;
		Mix_Music *music;
		int channel;
		int type;
	public:
		Audio(std::string fileName, int type);
		~Audio();
		void play(int n);
		void stop();
		void pause();
		void resume();
};

#endif
