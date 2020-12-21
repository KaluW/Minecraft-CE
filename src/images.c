#include <stdlib.h>

#include <graphx.h>
#include <fileioc.h>
#include <debug.h>

#include "images.h"
#include "defines.h"

gfx_sprite_t *tileset_tiles[MAX_TILE_COUNT];

void extract_tiles(void) {
	
	uint8_t slot, i;
	gfx_sprite_t *empty_tile;
	uint16_t pal_size;
	uint16_t *pal_ptr;
	uint8_t *tmp_ptr;
	gfx_sprite_t **tiles = tileset_tiles;
	
	ti_CloseAll();
	slot = ti_Open("MCT", "r");
	if(!slot) {
		missing_appvars();
	}
	
	pal_ptr = (uint16_t*)ti_GetDataPtr(slot);
	pal_size = *pal_ptr;
	pal_ptr ++;
	
	// set up the palette
	gfx_SetPalette(pal_ptr, pal_size, 0);
	tmp_ptr = (uint8_t*)pal_ptr;
	tmp_ptr += pal_size;
	
	// get the empty tile
	empty_tile = (gfx_sprite_t*)tmp_ptr;
	
	for(i = 0; i < MAX_TILE_COUNT; i ++) {
		tiles[i] = empty_tile;
	}
	
	for(i = 0; i < TILE_COUNT; i ++) {
		tiles[i] = (gfx_sprite_t*)tmp_ptr;
		tmp_ptr += TILE_DATA_SIZE;
	}
	
	// close the open file
	ti_CloseAll();

}