#pragma once
#include "../Utilities/Utils.h"
#include <SDL_image.h>
 
class GameObject
{
public:
    GameObject(const char* textureSheet, SDL_Renderer* ren, float x = 0.f, float y = 0.f );
    Vector2 position;

    void Update();
    void Render();
private:
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    SDL_Rect srRrect, destRect;
   
};
