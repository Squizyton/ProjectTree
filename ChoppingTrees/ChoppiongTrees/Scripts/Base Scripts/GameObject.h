#pragma once
#include "../Utilities/Utils.h"
#include <SDL_image.h>

#include "ECS.h"

class GameObject : Entity
{
public:
    GameObject(const char* textureSheet, Vector2* pos, float w, float h);
private:
    float width;
    float height;
    SDL_Texture* texture;
    SDL_Rect srRrect, destRect;
};
