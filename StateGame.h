#include "Sprite.h"
#include "State.h"
#include "Planet.h"
#include "TileMap.h"
#include "TileSet.h"
#include "InputManager.h"
#include "Obstaculo.h"
#include "FollowerObject.h"
#include <vector>
#include "AccObject.h"
#include "Audio.h"
#include "Timer.h"
#include "DirectionObject.h"
#include "NPCObject.h"
#include "Animation.h"
#include "Ar.h"

#ifndef STATEGAME_H
#define STATEGAME_H

#define SCROLL 10.0f
#define SCROLL_C1 0.1f
#define SCROLL_C2 0.2f
#define SCROLL_BLOCO 0.3f
#define TILE_SIZE 75
#define TILEMAP_SIZE 16
#define N_TEXTURES 30
#define SAVEP1 15000
#define SAVEP2 31992

#define ARX1 468
#define ARY1 354

#define ARX2 718
#define ARY2 120 //92

#define ARX3 1016
#define ARY3 352

#define ARX4 2056
#define ARY4 340

#define ARX5 2420
#define ARY5 84

#define ARX6 2830
#define ARY6 342

#define ARX7 3162
#define ARY7 18

#define ARX8 3454
#define ARY8 346

#define MUROX1 15120
#define MUROX2 35120

#define POPCORNW 39
#define POPCORNH 49

#define NPIPOCAS 20


class StateGame : public State{
  private:
    Timer coolDown;
    TileSet *tileSet;
    TileMap *tileMap;
    DirectionObject *dove;
    NPCObject *borus;
    Obstaculo *bloco;
    Obstaculo *muro;
    Obstaculo *muro2;
		Sprite *buttonPause;
 
    Ar *air[16];
    //vector<Obstaculo*> pipocas;
		Obstaculo *pipocas[20];
    int saveStack;
    int save;
    int n_pipocas;
    
    vector<Obstaculo*> blocos;
 
		int cont;
    int isPause;

    int stateReturn;
    //int stack;
    float boomX, boomY;
    float frangoX, frangoY;
    int speedCamX;
    Audio *sfx;
		Audio *sfxBoost;
    Audio *music;
    

  public:
   
    static float cameraX;
    static float cameraY;
    float cameraSpeedX;
    float cameraSpeedY;
    //Animation *shipAnimation;
    Animation *boom;
		Animation *teste;
    Sprite *bg;
		Sprite *doveFinal;
    Sprite *balao;
    Sprite *aviao;
    Sprite *muroSprite;
	  Sprite *arSprite;
    Sprite *pipocaSprite;
    Sprite* status0;
		Sprite* status1;
		Sprite* status2;
		Sprite* status3;

		Animation *borusAnimation;
    Animation *doveAnimation;
    Animation *doveDepenado;
    


    /* funcoes */
    StateGame(){};
    void load(int stack);
    int unload();
    int update(int dt);
    void render();
    void pause();
    void run();
    void processEvents();
    void addPlanet();
    void checkPlanets();
    void checkCollision(int dt);
    
};

#endif
