#include "State.h"
#include "Sprite.h"
#include "Text.h"
#include "InputManager.h"
#include "Audio.h"
#include "Animation.h"


#ifndef STATEMENU_H
#define STATEMENU_H

class StateMenu : public State {
	
	private:
		Sprite *bg;
    Sprite *jogar_on;
    Sprite *jogar_off;
		Sprite *ajuda_on;
		Sprite *ajuda_off;
		Sprite *story_on;
		Sprite *story_off;
		Sprite *sair_on;
		Sprite *sair_off;
		Animation *frameMenu1;
		Animation *frameMenu2;
    int jogar, ajuda, story, sair;
		/*Text *menu;
		Text *instrucoes;
		Text *voltar;
		Text *sair;*/
		Audio *music;
		int returnState;
    int animateMenu;
    int animacao;
	public:
		StateMenu(){};
		void load(int stack);
		int unload();
		int update(int dt);
		void render();
};

#endif
