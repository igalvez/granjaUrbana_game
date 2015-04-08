#include "TileMap.h"
#include "TileSet.h"
#include "ctype.h"

#define COLUNAS_MAP 3
#define WIDTH 374
#define HEIGHT 300

#define TESTE perror("teste2");
using namespace std;

TileMap :: TileMap(int mapWidth, int mapHeight, int tileSize, int layers, TileSet *tileSet){
  FILE *newteste;
  this->mapWidth = mapWidth;
  this->mapHeight = mapHeight;
  this->mapLayers = layers;
  this->tileSet = tileSet;
  newteste = fopen("testeTM.txt","w");
  /* Redimensionando matriz */
  tileMatrix.resize(layers);
  fprintf(newteste,"layers %d\n",layers);
  for(int x=0; x < layers; x++){
    tileMatrix[x].resize(mapHeight); //linhas
  }
  fprintf(newteste,"linhas %d\n",mapHeight);
  for(int x=0; x < layers; x++){
    for(int y=0; y < mapHeight ; y++){
      tileMatrix[x][y].resize(mapWidth); //colunas
    }
  }
  fprintf(newteste,"linhas %d\n",mapWidth);
   fclose(newteste);
   
  /* Inicializando matriz */
  for(int x=0; x < layers; x++){
    for(int y=0; y < mapHeight; y++){
      for(int z=0; z < mapWidth; z++){
        tileMatrix[x][y][z] = -1;
      }  
    }
  }

}
TileMap :: TileMap(string mapa, TileSet *tileSet)
{
  this->tileSet = tileSet;
  mapWidth = 0;
  mapHeight = 0;
  mapLayers = 0;
  load(mapa);
 
}
    
void TileMap :: load(string mapPath)
{
  int i = 0;
  vector<int> posicoes;
  char c1, c2;
  int d, u, aux,coluna,linha,layer;
  bool readD;
  FILE *arquivo;
  arquivo = fopen(mapPath.c_str(),"r");
  c1=0;
  d=0;
  u=0;
  fscanf(arquivo,"%d,%d,%d,",&mapHeight,&mapWidth,&mapLayers);
 /* while(((c1=fgetc(arquivo))!=EOF)&&(i<3)){
    //c1 = fgetc(arquivo);
    if(isdigit(c1)){
      if(readD){
        u = c1 - 48;
        readD = false;
        
        printf("U %d\n", u);

        
      }
      else{
        d = c1 - 48;
        readD = true;
        printf("D %d\n", d);
      }
    }
    if((c1==',')){
      aux = d*10 + u;
      dimensoes[i] = aux;
      //posicoes.bush_back(aux);
      readD = false;
      i++;
    }
  }
  mapWidth = dimensoes[0];
  mapHeight = dimensoes[1];
  mapLayers = dimensoes[2];*/
  
  tileMatrix.resize(mapLayers);
  for(int x=0; x < mapLayers; x++){
    tileMatrix[x].resize(mapHeight);
    for(int y=0; y < mapHeight ; y++){
      tileMatrix[x][y].resize(mapWidth);
    }
  }
  printf("linhas %d\n", mapHeight);
  printf("colunas %d\n", mapWidth);
  printf("camadas %d\n", mapLayers);
  linha = 0;
  coluna = 0;
  layer = 0;
  c2=0;
  i=0;
  aux=0;
  
  readD = false;
  printf("LINHA %d \n", linha);
  while(((c1=fgetc(arquivo))!=EOF)){
    printf("\n in while \n");
   // c1 = fgetc(arquivo);
		printf("c1 %c \n",c1);
    if(isdigit(c1)){
      if(readD == true){
        u = c1 - 48;
        readD = false;
        printf("U %d\n", u);
        
      }
      else{
        d = c1 - 48;
        readD = true;
        printf("D %d\n", d);
      }
    }
    else if((c1==',')){
      printf("\n COLUNA %d \n",coluna);
      aux = d*10 + u;
			printf(" %d ", aux);
      at(layer,linha,coluna) = aux;
      printf(" %d ", aux);
      coluna++;
      i++;
    }
    else if(c1=='\n'){
      //readD=true;
      if(c2 == ','){
        coluna = 0;
        linha++;
        if(linha>=mapHeight){
          linha = 0;
          layer++;
        }
        printf("\nLINHA %d \n", linha);
      }
    }
    c2=c1;
  }
      
  
  fclose(arquivo);
      
    
    
    
}

/*void TileMap :: load(string mapPath){
  
   
  Carrega o mapa a partir de um arquivo. O formato desse mapa pode e deve
  ser definido arbitrariamente.
  Sugestão: Usar um formato que pode ser gerado por um editor de TileMap,
  como por exemplo o Tiled. Se esse formato se mostrar muito complicado,
  usar uma simplificação.
  Width, height e layers devem estar definidos no arquivo do tilemap. 
  
  


}*/

void TileMap :: setTileset(TileSet *tileSet){

  this->tileSet = tileSet;

}

int& TileMap :: at(int x, int y, int z ){
  return tileMatrix[x][y][z];
}

void TileMap :: renderLayer(float cameraX, float cameraY, int layer){
  int imax,jmax;
  int index;
	int fator = 0;
	
	int m = 0;
	

  imax = tileMatrix[0].size();
  jmax = tileMatrix[0][0].size();
	printf(" \n imax %d \n",imax);
	printf("\n jmax %d \n",jmax);
	printf(" \n camx %f \n",cameraX);
	printf("\n camy %f \n",cameraY);

  m = ((int)cameraX)/1122;
  fator =   1122 * (m );
  printf("\n camerax mod %d\n",m);

   
  for(int i = 0; i<imax ; i++)
  {
    // printf("\nlinhA %d\n", i);
     for(int j = 0 ; j<jmax; j++)
     {
        index = tileMatrix[layer][i][j] - 1;
       // printf("antes %d ",index);
        if(index>=0)
         {
          	printf("\n WIDTH * i = %d \n ",i*WIDTH);
						printf("\n fator = %d \n ",fator);
						tileSet->render(index, i*374 + fator - cameraX, 600 - 300 );
					 /*if(repeat){
           		m = fator;
							i = -1;
							repeat = false;
					 }
					 else{
							tileSet->render(index, i*374 + m - cameraX, j*374 + m - cameraY);
						}*/
           //printf("%d index
         }
      }
   }   

}
    
    
void TileMap :: render(float cameraX, float cameraY){
 /*
  Checa se o tileSet não é nulo. Caso não seja:
  Itera em toda a matriz, checando se o índice armazenado é < 0. Caso seja,
  renderiza aquele tile.
  Para renderizar, é necessário passar a posição correta daquele tile na tela
  (posição do tile * dimensão do tile) e levar em consideração a posição da
  câmera.
 */
 int imax,jmax;
 int index;
  if( tileSet!=NULL)
  {

     imax = tileMatrix[0].size();
     jmax = tileMatrix[0][0].size();
     for(int i = 0; i<imax ; i++)
     {
        for(int j = 0 ; j<jmax; j++)
        {
           if(tileMatrix[0][i][j]>=0)
           {
             index = tileMatrix[0][i][j];
             tileSet->render(index, i*75 - cameraX, j*75 - cameraY);
           }
        }
     }   
  }
}

int TileMap :: width(){
  return mapWidth;
}

int TileMap :: height(){
  return mapHeight;
}

int TileMap :: layers(){
  return mapLayers;
}
