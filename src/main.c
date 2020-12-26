#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fileioc.h>
#include <graphx.h>
#include <keypadc.h>

#include "data.h"
#include "defines.h"
#include "images.h"
#include "interactions.h"
#include "mobs.h"
#include "player.h"
#include "terrain.h"

player_t player;
game_t game;

extern unsigned char chunk_map[];
bool inGame = false; // will replace with game.exit

// Almost want to shove these into its own module
void titleMenu(void);
void achievementsMenu(void);
void optionsMenu(void);
void createNewWorld(void);
void loadWorld(void);
void gameEngine(void); 

void missing_appvars(void) {
	
    gfx_End();
    os_SetCursorPos(0, 0);
    os_PutStrFull("Err: Missing AppVars");
    while(!os_GetCSC());
    exit(0);
	
}

void keypad_handler(void) {
	
	bool press_up;
	kb_key_t g1_key, g2_key, g7_key;
	
	kb_Scan();
	
	// read keypad data
	g1_key = kb_Data[1];
	g2_key = kb_Data[2];
	g7_key = kb_Data[7];
	
	pressed_f1 = (g1_key & kb_Yequ);
	pressed_f2 = (g1_key & kb_Window);
	pressed_f3 = (g1_key & kb_Zoom);
	pressed_f4 = (g1_key & kb_Trace);
	pressed_f5 = (g1_key & kb_Graph);
	
	pressed_2nd = (g1_key & kb_2nd);
	pressed_Alpha = (g2_key & kb_Alpha);
	
	pressed_down = (g7_key & kb_Down);
	pressed_left = (g7_key & kb_Left);
	pressed_right = (g7_key & kb_Right);
	press_up = (g7_key & kb_Up);
	
	// establishing the existence of gravity
	if (allow_up_press) {
		pressed_up = press_up;
	} else if (!press_up) {
		allow_up_press = true;
	}
	
}

/*
void main(void) {

	gfx_Begin( gfx_8bpp );
	// gfx_SetDrawBuffer();
	
	extract_tiles();
	
	
	extract_sprites();
	
	titleMenu();
	
	while(inGame) {
		
		gameEngine();
		
	}
	
	generateChunk();
	
	// Should have some sort of universal exit function here
}
*/

void main(void)
{
	sk_key_t key;
    unsigned int x_offset = 0;
    unsigned int y_offset = (CHUNK_HEIGHT / 2) * TILE_HEIGHT;
    gfx_tilemap_t tilemap;
	
	tilemap.map         = chunk_map;
    tilemap.tiles       = tileset_tiles;
    tilemap.type_width  = gfx_tile_16_pixel;
    tilemap.type_height = gfx_tile_16_pixel;
    tilemap.tile_height = TILE_HEIGHT;
    tilemap.tile_width  = TILE_WIDTH;
    tilemap.draw_height = TILEMAP_DRAW_HEIGHT;
    tilemap.draw_width  = TILEMAP_DRAW_WIDTH;
    tilemap.height      = CHUNK_HEIGHT;
    tilemap.width       = CHUNK_WIDTH;
    tilemap.y_loc       = 0;
    tilemap.x_loc       = 0;
	
	srand(rtc_Time());
	gfx_Begin();
	
	extract_tiles();
	
	generateChunk();
	
	gfx_FillScreen(1);
    gfx_SetColor(1);
    gfx_SetTextFGColor(0);
    gfx_SetTextBGColor(1);

    /* Draw to buffer to avoid tearing */
    gfx_SetDrawBuffer();

    /* Set monospace font with width of 8 */
    gfx_SetMonospaceFont(8);
	
	do
    {

        /* Get the key */
        key = os_GetCSC();
		
		// Draw sky
		gfx_FillScreen(1);
		
        /* Draw tilemap and coords */
        gfx_TransparentTilemap(&tilemap, x_offset, y_offset);
        gfx_FillRectangle(0, 0, 320, 16);
        gfx_PrintStringXY("x offset:", 48, 4);
        gfx_PrintUInt(x_offset, 4);
        gfx_PrintString(" y offset:");
        gfx_PrintUInt(y_offset, 4);

        /* Do something based on the keypress */
        switch (key)
        {
            case sk_Down:
                if (y_offset < (CHUNK_HEIGHT * TILE_HEIGHT) - (TILEMAP_DRAW_HEIGHT * TILE_HEIGHT))
                {
                    y_offset += TILE_HEIGHT;
                }
                break;

            case sk_Left:
                if (x_offset)
                {
                    x_offset -= TILE_WIDTH;
                }
                break;

            case sk_Right:
                if (x_offset < (CHUNK_WIDTH * TILE_WIDTH) - (TILEMAP_DRAW_WIDTH * TILE_WIDTH))
                {
                    x_offset += TILE_WIDTH;
                }
                break;

            case sk_Up:
                if (y_offset)
                {
                    y_offset -= TILE_HEIGHT;
                }
                break;

            default:
                break;
        }

        gfx_SwapDraw();

    } while (key != sk_Enter);
	
	gfx_End();	
}


void titleMenu(void) {
	
	achievementsMenu();
	optionsMenu();
	
	createNewWorld();
	loadWorld();
	
}

void achievementsMenu(void) {
	
}

void optionsMenu(void) {
	
}

void createNewWorld(void) {

	generateChunk(); 
	spawnMobs();
	
	// Other stuff to setup world
}

void loadWorld(void) {
	
	// Load world from appvar
	
}

void gameEngine(void) {
	
	updateTerrain();
	updateMobs();
	updatePlayer();
	
}