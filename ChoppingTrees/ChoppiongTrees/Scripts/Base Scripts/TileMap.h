#pragma once
#include "../Game.h"

class TileMap
{
public:
    TileMap();
    ~TileMap();
    void LoadMap();
    void DrawMap();
    void GenerateMap();
    void LoadTextures();
    
private:
    SDL_Rect src, dest;
    SDL_Texture* dirtTexture;

    int map[20][25];
    

};
