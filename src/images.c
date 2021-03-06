#include <graphx.h>
#include <fileioc.h>

#include "images.h"
#include "defines.h"

gfx_sprite_t* tileset_tiles[MAX_BLOCK_TILE_COUNT];

void extract_tiles(void)
{
	ti_CloseAll();
	uint8_t slot = ti_Open("MCT", "r");
	if (!slot)
		missing_appvars();

	gfx_sprite_t* empty_tile;
	uint16_t pal_size;
	uint16_t* pal_ptr;
	uint8_t* tmp_ptr;
	gfx_sprite_t** tiles = tileset_tiles;

	pal_ptr = (uint16_t*)ti_GetDataPtr(slot);
	pal_size = *pal_ptr;
	pal_ptr++;

	// set up the palette
	gfx_SetPalette(pal_ptr, pal_size, 0);
	tmp_ptr = (uint8_t*)pal_ptr;
	tmp_ptr += pal_size;

	// get the empty tile
	empty_tile = (gfx_sprite_t*)tmp_ptr;

	for (uint8_t i = 0; i < MAX_BLOCK_TILE_COUNT; i++)
		tiles[i] = empty_tile;

	// store tile pointers
	for (uint8_t i = 0; i < TILE_COUNT; i++)
	{
		tiles[i] = (gfx_sprite_t*)tmp_ptr;
		tmp_ptr += TILE_DATA_SIZE;
	}

	// close the open file
	ti_CloseAll();
}