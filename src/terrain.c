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
	gfx_PrintUInt(player.x / TILE_WIDTH, 3);
	gfx_PrintString(" y offset:");
	gfx_PrintUInt(player.y / TILE_HEIGHT, 2);
}

void generateWorld(void)
{
	// starting "height" of terrain; adjust start_y every new chunk to connect them together
	uint8_t start_y = randInt(CHUNK_HEIGHT / 4, CHUNK_HEIGHT * 3 / 4);

	for (uint8_t i = 0; i < CHUNKS; i++)
		generateChunk(i, &start_y);
}

void generateChunk(uint8_t chunkOffset, uint8_t* start_y)
{
	float y; // (x, y) determines the top block of terrain in a given column in the chunk modeled by the curve pattern
	float pA, pB, z; // interpolate curve line between 'pA' and 'pB' using seed 'z'
	uint8_t amp = randInt(2, 12), wl = randInt(1, 10); // amplitude and wavelength

	z = rand_0_1() * LCG_M; // starting seed value

	pA = lcg(&z);
	pB = lcg(&z);

	for (uint8_t x = 0; x < CHUNK_WIDTH; x++) // Go through each 'x' column in chunk and fill in terrain accordingly
	{
		if (x % wl == 0)
		{
			// Randomize curve shape after every period
			pA = pB;
			pB = lcg(&z);
			y = CHUNK_HEIGHT + pA * amp - *start_y;
		}
		else
		{
			// model top block in terrain along curve shape
			y = CHUNK_HEIGHT + interpolate(pA, pB, ((x % wl) / (float)wl)) * amp - *start_y;
		}

		y = (uint8_t)y;

		uint8_t dirtLayer = randInt(2, 4);
		uint8_t* tile;

		// Fill column with appropriate blocks - will probably end up making this its own function as complexity of chunk generation increases
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

	// adjust new start_y for next chunk so as to makes ends of chunks look seamless
	*start_y = CHUNK_HEIGHT - y;
}

float rand_0_1(void)
{
	return (float)rand() / ((float)RAND_MAX + 1);
}

float lcg(float* z)
{
	// For some reason I can't directly use the #defines directly?
	uint32_t M = LCG_M;
	uint32_t A = LCG_A;
	uint32_t C = LCG_C;

	float zd = *z - floor(*z);
	*z = (A * (int)*z + C) % M + zd;

	return (*z + zd) / (float)M - 0.5;
}

float interpolate(float pA, float pB, float pX)
{
	float f = (1 - cos(pX * M_PI)) * 0.5;

	return pA * (1 - f) + pB * f;
}