#include <vector>
#include "Sprite.h"
#include <string.h>


#ifndef TILESET_H
#define TILESET_H
class TileSet{
  private:
    int tileWidth;
    int tileHeight;
    int lines, columns;
    int useSingleFile;
    Sprite *tileSet;
    SDL_Rect *destRect;
    
  public:
    vector<Sprite*> *vTiles;
    TileSet(string filePath, int lines, int columns);
    TileSet(int tileWidth, int tileHeight, string filePath);

    TileSet(int tileWidth, int tileHeight);
    void addTile(string filePath);
    void render(int index, float posX, float posY);
    bool usingSingleFile();
    int getTileWidth();
    int getTileHeight();
   
};
#endif
