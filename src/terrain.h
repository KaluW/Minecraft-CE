#ifndef TERRAIN_H
#define TERRAIN_H

#define CHUNK_WIDTH 	32
#define CHUNK_HEIGHT	128

#define CHUNKS 1

extern unsigned char world_map[];

void updateTerrain(void);

void generateWorld(void);
void generateChunk(uint8_t offset);

float rand_0_1(void);
float randomize(float *z);
float interpolate(float pointA, float pointB, float pointX);

#endif