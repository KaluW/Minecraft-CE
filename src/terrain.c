#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include "terrain.h"

#include "defines.h"
#include "images.h"

void updateTerrain(void) {
	
	/*
	
	In the current chunk, check for changes in
	- light interaction (adjacent block was destroyed/added)
	- time (grow plants, animals)
	- player's X position and generate new chunk when approaching the edge and there isn't another chunk beyond it
	- ...
	
	*/
}

void generateChunk(void) {
	
	// Incorporate chunk generator and its child functions here
	// Remember to incorporate new chunk into the Overworld Array
	
	// dummy code
	uint8_t i, j;
	
	for( i = 0; i < 4; i ++) {
		for( j = 0; j < 16; j ++) {
			gfx_TransparentSprite(tileset_tiles[i * TILE_WIDTH + j], j * 16, i * 16);
		}
	}
			
	while(!os_GetCSC());
}