#include "TileMap.h"

#include <iostream>

#include "TextureManager.h"
#include "../Utilities/PerlinNoise.hpp"

TileMap::TileMap()
{
  
}


/**
 * \brief Generate a map already made.
 */
void TileMap::LoadMap()
{
    
}

//TODO:: Multithread this
void TileMap::GenerateMap(int width, int height)
{
    const siv::PerlinNoise::seed_type seed = 123456u;

    const siv::PerlinNoise perlin{ seed };

    double map[width][height];

    
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            const double noise = perlin.octave2D_01((x * 0.01), (y * 0.01),8);
            std::cout << noise << "\t";
            
        }
    std::cout << "\n";
    }
}
