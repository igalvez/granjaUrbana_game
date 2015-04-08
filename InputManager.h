#include <stdio.h>
#include <stdlib.h>
#include "SDLBase.h"

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#define N_KEYS SDLK_LAST
#define N_MOUSE_BUTTONS 3

class InputManager{
  private:
    Uint8 mouse;
    Uint8 *teclado;
    Uint8 keyDown[N_KEYS];
    Uint8 keyUp[N_KEYS];
    Uint8 mouseDown[N_MOUSE_BUTTONS];
    Uint8 mouseUp[N_MOUSE_BUTTONS];
    int mouseX, mouseY;
    bool quitGame;
    static InputManager *instance;
    
    InputManager();
  public:
    static InputManager* getInstance();
    void update();
    bool iskeyDown(int key);
    bool iskeyUp(int key);
    bool isKeyPressed(int key);
    bool isMouseDown(int button);
    bool isMouseUp(int button);
    bool isMousePressed(Uint8 button);
    int mousePosX();
    int mousePosY();
    bool isMouseInside(SDL_Rect *rect);
    bool QuitGame();
 };
 
 #endif
  
