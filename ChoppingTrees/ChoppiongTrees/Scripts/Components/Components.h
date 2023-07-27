#pragma once
#include "../Base Scripts/ECS.h"
#include "../Utilities/Utils.h"


class PositionComponent : public Component
{
private:
    Vector2* position;

public:
    PositionComponent()
    {
        position = new Vector2();
    }


    void SetPos(float x, float y)
    {
        position->x = x;
        position->y = y;
    }

    void Update() override
    {
        //TODO:: Remove
        position->x++;
        position->y++;
    }
};
