#pragma once
#include "../Utilities/Utils.h"
#include <SDL_image.h>

class GameObject
{
public:
   
    GameObject(const char* textureSheet, Vector2* pos, float w, float h);

    Vector2* position;

    void Update();
    void Render();

private:
    float width;
    float height;


    SDL_Texture* texture;
    SDL_Renderer* renderer;
    SDL_Rect srRrect, destRect;
};
