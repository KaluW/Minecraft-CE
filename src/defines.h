#ifndef DEFINES_H
#define DEFINES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

// constant members of the Linear Congruential Generator (LCG) - Used in randomnizing terrain
#define LCG_M 2147483648
#define LCG_A 1664525
#define LCG_C 1

#define TILE_COUNT 32
#define MAX_BLOCK_TILE_COUNT 32

#define TILE_EMPTY 0

void missing_appvars(void);

typedef struct {
	
	uint8_t time_of_day;
	bool exit;
	
} game_t;

extern game_t game;

#define TILE_DATA_SIZE 258

#define TILE_WIDTH 16
#define TILE_HEIGHT 16

#define TILEMAP_DRAW_WIDTH 21
#define TILEMAP_DRAW_HEIGHT 15

#endif