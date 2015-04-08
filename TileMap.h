#include "TileSet.h"


#ifndef TILEMAP_H
#define TILEMAP_H 

#define TILE_SIZE 75

class TileMap{
  private:
    std::vector<std::vector<std::vector<int> > > tileMatrix;
    TileSet *tileSet;
    int mapWidth, mapHeight, mapLayers;
    
  public:
    TileMap(int mapWidth, int mapHeight, int tileSize, int layers, TileSet *tileSet);
    TileMap(string mapa, TileSet *tileSet);
    void load(string mapPath);
    void setTileset(TileSet *tileSet);
    int& at(int x, int y, int z);
    void render(float cameraX, float cameraY);
    void renderLayer(float cameraX, float cameraY, int layer);
    int width();
    int height();
    int layers();
    
};

#endif
