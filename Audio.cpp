#include "Audio.h"

Audio :: Audio(std::string fileName, int type)
{
	this->fileName = fileName;
	this->type = type;
	if(type == 0){
		sound = Mix_LoadWAV(fileName.c_str());
  }
  else{
		music = Mix_LoadMUS(fileName.c_str());
  }
  channel = -1;
}

Audio :: ~Audio()
{
  Mix_FreeMusic(music);
	Mix_FreeChunk(sound);
}

void Audio :: play(int n)
{
	if(type == 1){
		Mix_PlayMusic(music,n);
  }
  else {
		channel = Mix_PlayChannel(channel, sound, n);
  }
}

void Audio :: stop()
{
	if(type == 0){
		Mix_HaltChannel(channel);
  }
  else {
		Mix_FadeOutMusic(3);
  }
}
void Audio :: pause(){
	if(type==1){
		Mix_PauseMusic();
  }
}

void Audio :: resume(){
	if(type==1){
		Mix_ResumeMusic();
  }
}
