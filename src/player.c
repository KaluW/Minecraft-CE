#include "defines.h"
#include "player.h"
#include "terrain.h"

bool pressed_f1 = false;
bool pressed_f2 = false;
bool pressed_f3 = false;
bool pressed_f4 = false;
bool pressed_f5 = false;

bool pressed_2nd = false;
bool pressed_Alpha = false;

bool pressed_down = false;
bool pressed_left = false;
bool pressed_right = false;
bool pressed_up = false;

bool allow_up_press = true;


void updatePlayer(void) {
	
	// 1. Update controls
	move_player();
	
	// 2. Draw
	
	/* 3. Trigger interaction w/ terrain
		- Land/Water
		- Falling/Jumping/Swimming
		- Building/Destroying blocks
		- Update inventory
	*/
	
	// 4. Trigger interaction w/ mob
	
}

void move_player(void)
{
	if (pressed_left)
		if (player.x)
			player.x -= TILE_WIDTH;

	if (pressed_right)
		if (player.x < (CHUNK_WIDTH * TILE_WIDTH) - (TILEMAP_DRAW_WIDTH * TILE_WIDTH))
			player.x += TILE_WIDTH;

	if (pressed_up)
		if (player.y)
			player.y -= TILE_HEIGHT;

	if (pressed_down)
		if (player.y < (CHUNK_HEIGHT * TILE_HEIGHT) - (TILEMAP_DRAW_HEIGHT * TILE_HEIGHT))
			player.y += TILE_HEIGHT;
}