#ifndef TERRAIN_H
#define TERRAIN_H

#define CHUNK_WIDTH 	32
#define CHUNK_HEIGHT	128
#define CHUNKS 7

// constant members of the Linear Congruential Generator (LCG) - Used in randomizing terrain
#define LCG_M 2147483648
#define LCG_A 1664525
#define LCG_C 1

extern unsigned char world_map[];

void updateTerrain(void);

void generateWorld(void);
void generateChunk(uint8_t chunkOffset);

float rand_0_1(void);
float randomize(float* z);
float interpolate(float pointA, float pointB, float pointX);

#endif