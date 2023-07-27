#include "Game.h"

#include <SDL_image.h>
#include <iostream>
#include "Base Scripts/GameObject.h"

#include "Base Scripts/ECS.h"
#include "Components/Components.h"


GameObject* player;
SDL_Renderer* Game::renderer = nullptr;

Manager manager;

auto& newPlayer(manager.AddEntity());

bool Game::Init()
{
    //If we did not intialize properly then return an error
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Crash";
        return false;
    }


    //Create the window
    window = SDL_CreateWindow("Chopping Trees",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1270, 800, 0);


    //if Window failed to recreate
    if (!window)
    {
        return false;
    }

    // Create the renderer: Pass in the window : he index of the rendering driver to initialize, or -1 to initialize the first one supporting the requested flags : Special Flags - Use Hardware Acceleration, And VSync
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
        return false;
    }

    SDL_Surface* tmpSurface = IMG_Load("assets/paunch.png");

    auto test = new Vector2(50.f,50.f);
    player = new GameObject("assets/paunch.png",test,32.f,32.f);
    auto& newPlayer(manager.AddEntity());
    newPlayer.AddComponent<PositionComponent>();
    
    return true;
}


void Game::GameLoop()
{
    while (isRunning)
    {
        HandleEvents();
        Update();
        Draw();
    }
}


void Game::HandleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }

        //Get All keys by using null
        const Uint8* keystates = SDL_GetKeyboardState(nullptr);

        if (keystates[SDL_SCANCODE_ESCAPE])
        {
            isRunning = false;
        }
    }
}

void Game::Update()
{
    player->Update();

    //Updates the entities;
    manager.Update();
}


void Game::Draw()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    


    player->Render();


    SDL_RenderPresent(renderer);
}


void Game::ShutDown()
{
    //Destroys the renderer
    SDL_DestroyRenderer(renderer);
    //Destroys the window
    SDL_DestroyWindow(window);
    ///Clean up all initialized subsystems. You should call this function even if you have already shutdown each initialized subsystem with SDL_QuitSubSystem().
    ///It is safe to call this function even in the case of errors in initialization.
    SDL_Quit();
}
