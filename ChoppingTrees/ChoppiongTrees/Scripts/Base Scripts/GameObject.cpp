#include "GameObject.h"

#include "TextureManager.h"

/**
    * \brief 
    * \param textureSheet The Sheet of the character
    * \param pos position of where the object will begin at
    * \param w Scale of object
    * \param h Scale of object
    */
GameObject::GameObject(const char* textureSheet, Vector2* pos, float w, float h)
{
    texture = TextureManager::LoadTexture(textureSheet,Game::renderer);
    width = w;
    height = h;
    srRrect.h = static_cast<int>(height);
    srRrect.w = static_cast<int>(width);
    position = pos;
}


void GameObject::Update()
{
    //srcRect is the base
    srRrect.x = 0;
    srRrect.y = 0;


    destRect.x = position->x;
    destRect.y = position->y;

    //DestRect is what the Renderer will target
    destRect.w = srRrect.w * 5;
    destRect.h = srRrect.h * 5;
}


void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, texture, &srRrect, &destRect);
}
