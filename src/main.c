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

#include "defines.h"
#include "images.h"
#include "interactions.h"
#include "mobs.h"
#include "player.h"
#include "terrain.h"

player_t player;
game_t game;

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

void main(void) {

	gfx_Begin( gfx_8bpp );
	// gfx_SetDrawBuffer();
	
	extract_tiles();
	
	/*
	
	extract_sprites();
	
	titleMenu();
	
	while(inGame) {
		
		gameEngine();
		
	}
	
	*/
	
	generateChunk();
	
	/* Should have some sort of universal exit function here */
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