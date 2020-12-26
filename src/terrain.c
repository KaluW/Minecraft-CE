#include <stdint.h>
#include <graphx.h>
#include <tice.h>
#include <math.h>

#include "terrain.h"

#include "data.h"
#include "defines.h"
#include "images.h"

// Store all the terrain here
unsigned char chunk_map[CHUNK_WIDTH * CHUNK_HEIGHT];
	
void updateTerrain(void) {
	
	/*
	
	In the current chunk, check for changes in
	- light interaction (adjacent block was destroyed/added)
	- time (grow plants, animals)
	- player's X position and generate new chunk when approaching the edge and there isn't another chunk beyond it
	- ...
	
	*/
}

void generateChunk(void) {
	
	/*
	- Incorporate chunk generator and its child functions here
	- Remember to incorporate new chunk into the Overworld Array
	*/
	
	uint8_t x = 0; // position along chunk
	uint8_t amp; // amplitude - height of curve
	uint8_t wl; // wavelength - width of curve
	uint8_t i, j, k; // for() loop vars
	uint8_t yOffset; // position up or down from "default" height of terrain;
	
	float y; // (x, y) determines the top block in a given column in the chunk modeled by the curve pattern
	float pointA, pointB, z; 
	
	y = CHUNK_HEIGHT;	
    yOffset = CHUNK_HEIGHT / 2;  // "default" height of terrain (the middle of the chunk)
	
	z = rand_0_1() * LCG_M;
    pointA = randFunc(LCG_M, LCG_A, LCG_C, &z),
    pointB = randFunc(LCG_M, LCG_A, LCG_C, &z);
	
	amp = 8, wl = 3; // Should adjust this according to biome eventually
    
    while(x < CHUNK_WIDTH) // Go through each column in chunk and fill in terrain accordingly
	{
        if(x % wl == 0) 
        {
			// Randomnize curve shape after every period
            pointA = pointB;
            pointB = randFunc(LCG_M, LCG_A, LCG_C, &z);
            y = CHUNK_HEIGHT + pointA * amp - yOffset;
			
        } else
		{
			// model top block in terrain along curve shape
            y = CHUNK_HEIGHT + interpolate(pointA, pointB, ((x % wl) / (float)wl)) * amp - yOffset;
			
        }
				
		//Store the terrain in a 32x128 tilemap chunk
		for(i = 0; i < y; i ++) // fill in blocks over the top block accordingly
		{
			if (chunk_map[CHUNK_WIDTH * i + x] < 1) //if the current tile isn't already defined; used for pregenerated features like trees
				chunk_map[CHUNK_WIDTH * i + x] = AIR;
				
		}
		
		fillInTerrain(x, (uint8_t)y); // fill in blocks under the top block 
		
        x ++;
    }  
}
void fillInTerrain(uint8_t x, uint8_t y)
{
	uint8_t i, j, dirtLayer;
	
	dirtLayer = randInt(2,4);
	
	chunk_map[CHUNK_WIDTH * y + x] = GRASS;
	
	for(i = y + 1; i < y + dirtLayer; i ++)
		chunk_map[CHUNK_WIDTH * i + x] = DIRT;
	
	for(j = y + dirtLayer; j < CHUNK_HEIGHT; j ++)
		chunk_map[CHUNK_WIDTH*j + x] = STONE;
		
	chunk_map[CHUNK_WIDTH* (CHUNK_HEIGHT - 1) +x] = BEDROCK;
}

float rand_0_1(void)
{
	return (float) rand() / ((float) RAND_MAX + 1);
}
 
float randFunc(uint32_t M, uint32_t A, uint32_t C, float *z)
{
	float zd = *z - floor(*z);
	*z = (A * (int)*z + C) % M + zd;
	return (*z + zd) / (float)M - 0.5;

}
 
float interpolate(float pa, float pb, float px)
{
    float f = (1 - cos(px * M_PI)) * 0.5;
         
    return pa * (1 - f) + pb * f;
}