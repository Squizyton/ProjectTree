#include "GameObject.h"

#include "TextureManager.h"


GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, float x, float y)
{
    renderer = ren;
    texture = TextureManager::LoadTexture(textureSheet,ren);

    
}
