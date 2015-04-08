#include "InputManager.h"
    
InputManager* InputManager::instance = NULL;
    
InputManager :: InputManager(){
  int i;
  quitGame = false;
  for(i=0; i<N_KEYS; i++){
    keyDown[i]=0;
    keyUp[i] = 0;
  }
  for(i=0 ; i<N_MOUSE_BUTTONS; i++){
    mouseDown[i] = 0;
    mouseUp[i] = 0;
  }

}
 
InputManager*  InputManager :: getInstance()
{
  if(instance==NULL)
    instance = new InputManager();
  return instance;
}  
  
void InputManager :: update()
{
  SDL_Event event;
  int i;
  
  for(i=0; i<N_KEYS; i++){
    keyDown[i] = 0;
    keyUp[i] = 0;
  }
  for(i=0 ; i<N_MOUSE_BUTTONS; i++){
    mouseDown[i] = 0;
    mouseUp[i] = 0;
  }
  
  while(SDL_PollEvent(&event))
  {
  
    SDL_GetMouseState( &mouseX, &mouseY );
    teclado = SDL_GetKeyState(NULL);
    switch(event.type){
      case SDL_KEYDOWN:
          keyDown[event.key.keysym.sym] = true;
          printf("keydown\n");
          break;
      case SDL_KEYUP:
          keyUp[event.key.keysym.sym] = true;
          printf("keyup\n");
          break;
      case SDL_MOUSEBUTTONDOWN:
          mouseDown[event.button.button] = true;
          break;
      case SDL_MOUSEBUTTONUP:
          mouseUp[event.button.button] = true;
          break;
      case SDL_QUIT:
          quitGame = true;
          break;
    }
   }
          
}

bool InputManager :: iskeyDown(int key)
{
  return keyDown[key];
}

bool InputManager :: iskeyUp(int key)
{
  return keyUp[key];
}

bool InputManager :: isKeyPressed(int key)
{
  return teclado[key];
}

bool InputManager :: isMouseDown(int button)
{
  return mouseDown[button];
}
    
bool InputManager :: isMouseUp(int button)
{
  return mouseUp[button];
}

bool InputManager :: isMousePressed(Uint8 button)
{
  return mouseDown[button];
}
 
int InputManager :: mousePosX()
{
  return mouseX;
}
 
int InputManager :: mousePosY()
{
  return mouseY;
}
    
bool InputManager :: isMouseInside(SDL_Rect *rect)
{
  if((mouseX >= (rect->x)) && (mouseX <= (rect->x + rect->w)) && (mouseY >= (rect->y)) && (mouseY <= (rect->y + rect->h)))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool InputManager :: QuitGame()
{
  return quitGame;
}

