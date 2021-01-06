#ifndef TERRAIN_H
#define TERRAIN_H

#define CHUNK_WIDTH 	15
#define CHUNK_HEIGHT	128
#define CHUNKS			17

#define LCG_M 2147483648 // modulus
#define LCG_A 1103515245 // multiplier
#define LCG_C 12345 // increment

extern unsigned char world_map[];

void updateTerrain(void);

void generateWorld(void);
void generateChunk(uint8_t chunkOffset, uint8_t* start_y);

float rand_0_1(void);
float lcg(float* z);
float interpolate(float pA, float pB, float pX);

#endif