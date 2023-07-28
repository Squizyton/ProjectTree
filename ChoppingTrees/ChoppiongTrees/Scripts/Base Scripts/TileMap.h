#pragma once
#include "../Game.h"

class TileMap
{
public:
    TileMap();
    ~TileMap();
    void LoadMap();
    void DrawMap();
    void GenerateMap(int width, int height);
    void LoadTextures();
    
private:
    SDL_Rect src, dest;
    SDL_Texture* dirtTexture;

    

};
