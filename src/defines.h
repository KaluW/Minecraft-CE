#ifndef DEFINES_H
#define DEFINES_H

#include <graphx.h>

#define TILE_COUNT 32
#define MAX_BLOCK_TILE_COUNT 32

#define TILE_EMPTY 0

void missing_appvars(void);

extern gfx_tilemap_t tilemap;

typedef struct
{
	uint8_t chunk_id;
	uint8_t time_of_day;
	bool exit;
} game_t;

extern game_t game;

#define TILE_DATA_SIZE 258

#define TILE_WIDTH 16
#define TILE_HEIGHT 16

#define TILEMAP_DRAW_WIDTH 20
#define TILEMAP_DRAW_HEIGHT 15

#endif