#include <graphx.h>
#include <math.h>

#include "data.h"
#include "defines.h"
#include "images.h"
#include "player.h"
#include "terrain.h"

// Store all the terrain here
unsigned char world_map[CHUNK_WIDTH * CHUNK_HEIGHT * CHUNKS];

void updateTerrain(void)
{
	/*

	In the current chunk, check for changes in
	- light interaction (adjacent block was destroyed/added)
	- time (grow plants, animals)
	- player's X position and generate new chunk when approaching the edge and there isn't another chunk beyond it
	- ...

	*/

	// Draw sky
	gfx_FillScreen(1);

	/* Draw tilemap and coords */
	gfx_TransparentTilemap(&tilemap, player.x, player.y);
	gfx_FillRectangle(0, 0, 320, 16);
	gfx_PrintStringXY("x offset:", 48, 4);
	gfx_PrintUInt(player.x, 4);
	gfx_PrintString(" y offset:");
	gfx_PrintUInt(player.y, 4);
}

void generateWorld(void)
{
	// uint8_t yOffset = randInt(CHUNK_HEIGHT / 4, CHUNK_HEIGHT * 3 / 4); // starting "height" of terrain

	for (uint8_t i = 0; i < CHUNKS; i++)
		generateChunk(i);
}

void generateChunk(uint8_t chunkOffset)
{
	uint8_t yOffset = CHUNK_HEIGHT / 2; // position up or down from "default" height of terrain - used to connect different chunks together;

	float y; // (x, y) determines the top block in a given column in the chunk modeled by the curve pattern
	float pA, pB, z; // interpolate curve line between 'pA' (point A) and 'pB' (point B) using random 'z'
	uint8_t amp = randInt(2, 12), wl = randInt(1, 10); // amplitude and wavelength

	// y = CHUNK_HEIGHT;

	z = rand_0_1() * LCG_M;
	pA = randomize(&z);
	pB = randomize(&z);


	for (uint8_t x = 0; x < CHUNK_WIDTH; x++) // Go through each 'x' column in chunk and fill in terrain accordingly
	{
		if (x % wl == 0)
		{
			// Randomize curve shape after every period
			pA = pB;
			pB = randomize(&z);
			y = CHUNK_HEIGHT + pA * amp - yOffset;

		}
		else
		{
			// model top block in terrain along curve shape
			y = CHUNK_HEIGHT + interpolate(pA, pB, ((x % wl) / (float)wl)) * amp - yOffset;

		}

		y = (uint8_t)y;

		uint8_t dirtLayer = randInt(2, 4);
		uint8_t* tile;

		// Fill column with appropriate blocks
		for (uint8_t i = 0; i < CHUNK_HEIGHT; i++) {

			tile = &world_map[i * CHUNK_WIDTH * CHUNKS + x + chunkOffset * CHUNK_WIDTH];
			if (i < y)
			{
				*tile = AIR;
			}
			else if (i == y) {
				*tile = GRASS;
			}
			else if (i < y + dirtLayer) {
				*tile = DIRT;
			}
			else if (i < CHUNK_HEIGHT - 1) {
				*tile = STONE;
			}
			else {
				*tile = BEDROCK;
			}

		}

	}
}

float rand_0_1(void)
{
	return (float)rand() / ((float)RAND_MAX + 1);
}

float randomize(float* z)
{
	// for some reason if I use the #define directly, the chunk generation no longer works properly?
	uint32_t M = LCG_M, A = LCG_A, C = LCG_C;

	// I actually have no idea why this code needs to do exactly what it does :P
	float zd = *z - floor(*z);
	*z = (A * (int)*z + C) % M + zd;

	return (*z + zd) / (float)M - 0.5;
}

float interpolate(float pA, float pB, float pX)
{
	float f = (1 - cos(pX * M_PI)) * 0.5;

	return pA * (1 - f) + pB * f;
}