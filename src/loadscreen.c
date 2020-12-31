#include <graphx.h>

#include "defines.h"
#include "images.h"
#include "loadscreen.h"
#include "player.h"
#include "terrain.h"

void init_game(void)
{
    tilemap.map = world_map;
    tilemap.tiles = tileset_tiles;
    tilemap.type_width = gfx_tile_16_pixel;
    tilemap.type_height = gfx_tile_16_pixel;
    tilemap.tile_height = TILE_HEIGHT;
    tilemap.tile_width = TILE_WIDTH;
    tilemap.draw_height = TILEMAP_DRAW_HEIGHT;
    tilemap.draw_width = TILEMAP_DRAW_WIDTH;
    tilemap.width = CHUNK_WIDTH;
    tilemap.height = CHUNK_HEIGHT;
    tilemap.y_loc = 0;
    tilemap.x_loc = 0;

    player.x = 0;
    player.y = (CHUNK_HEIGHT / 2) * TILE_HEIGHT;

    game.chunk.id = 0;

    generateWorld();

	gfx_FillScreen(1);
    gfx_SetColor(1);
    gfx_SetTextFGColor(0);
    gfx_SetTextBGColor(1);

    gfx_SetMonospaceFont(8);
}

void titleMenu(void)
{
	achievementsMenu();
	optionsMenu();
	
	createNewWorld();
	loadWorld();
}

void achievementsMenu(void)
{
	
}

void optionsMenu(void)
{
	
}

void createNewWorld(void)
{
	generateWorld(); 
	// spawnMobs();
	// Other stuff to setup world
}

void loadWorld(void)
{
	// Load world from appvar
}