#pragma once
#include "GameObject.h"

class Tile : GameObject
{
public:
    bool isPassable;
    Tile(const char* textureSheet, Vector2* pos, float w, float h, bool passable)
        : GameObject(textureSheet, pos, w, h){}
};
