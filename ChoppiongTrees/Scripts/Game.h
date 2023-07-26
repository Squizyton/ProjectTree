#pragma once


#include <SDL.h>



class Game
{
public:
    bool Init();
    void GameLoop();
    void ShutDown();

private:
    bool isRunning = true;
    void HandleEvents();
    void Update();
    void Draw();

    //Get window as a pointer so we have direct access to it
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};
