#ifndef TERRAIN_H
#define TERRAIN_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#define CHUNK_WIDTH 	32
#define CHUNK_HEIGHT	128

void updateTerrain(void);
void generateChunk(void);

void fillInTerrain(uint8_t x, uint8_t y);
float rand_0_1(void);
float randFunc(uint32_t M, uint32_t A, uint32_t C, float *z);
float interpolate(float pointA, float pointB, float pointX);

#endif