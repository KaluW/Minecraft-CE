#ifndef TERRAIN_H
#define TERRAIN_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

void updateTerrain(void);
void generateChunk(void);

typedef struct {
	
	uint8_t yield; // Index of the item that it gives you when you break it.
	uint8_t hardness; // (wheat = 0, obsidian = 50) - numbers from actual minecraft
	uint8_t slow; // movement speed reduction through block
	
	/*
	Pointer to a function that will contain a certain block's unique properties such as:
		- abides by gravity
		- gives off light
		- puts you on fire
		- makes you sink
		- etc.
	*/
	void (*unique_properties)(void);
	
} block_t;

extern block_t blocks[];

/*

I will list all of the blocks and their corresponding properties here.
However, my index of blocks must match the tileset indices used to generate the tilemap.
I don't have the tileset you guys used (it's not in the git repo?), so it would be much appreciated if I recieved it :)

*/

#endif