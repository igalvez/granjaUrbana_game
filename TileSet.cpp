#include "TileSet.h"
using namespace std;





TileSet :: TileSet(int tileWidth, int tileHeight){
  this->tileWidth = tileWidth;
  this->tileHeight = tileHeight;
  useSingleFile = 0;
  lines = 0;
  columns = 0;
  tileSet = NULL;
  this->vTiles = new vector<Sprite *>;
}

TileSet :: TileSet(int tileWidth, int tileHeight, string filePath){
  int tilesetw;
  int tileseth;

  
  useSingleFile = true;
  this->tileWidth = tileWidth;
  this->tileHeight = tileHeight;
  tileSet = new Sprite(filePath);
  tilesetw = tileSet->getWidth();
  tileseth = tileSet->getHeight();
  columns = tilesetw/tileWidth;
  lines = tileseth/tileHeight;
  vTiles = NULL;
  

}

void TileSet :: addTile(string filePath){
  Sprite *tile;
  if(!useSingleFile){
    tile = new Sprite(filePath);
    vTiles->push_back(tile);
   }

}

void TileSet :: render(int index, float posX, float posY){

  int linha, coluna;
  if(useSingleFile){
    linha = index/columns;  
    coluna = index % columns;
   // printf("index %d  ", index+1);
   // printf("  POS %d  \n",coluna*tileWidth);
    tileSet->clip(coluna*tileWidth, linha*tileHeight, tileWidth, tileHeight);
    tileSet->render(posX,posY);
     
  }
  else {
    (*vTiles)[index]->render(posX,posY);
  }
}

bool TileSet :: usingSingleFile(){
  if(tileSet==NULL)
    return false;
  else
    return true;

}

int TileSet :: getTileWidth(){
  return tileWidth;
}
 
int TileSet :: getTileHeight(){
  return tileHeight;
}
