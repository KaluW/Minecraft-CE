#include <graphx.h>
#include <keypadc.h>

#include "data.h"
#include "defines.h"
#include "images.h"
#include "loadscreen.h"
#include "mobs.h"
#include "player.h"
#include "terrain.h"

game_t game;
player_t player;

gfx_tilemap_t tilemap;
extern unsigned char world_map[];

void missing_appvars(void)
{
	gfx_End();
	os_SetCursorPos(0, 0);
	os_PutStrFull("Err: Missing AppVars");
	while (!os_GetCSC());
	exit(0);
}

void handle_keypad(void)
{

	bool press_up;
	kb_key_t g1_key, g2_key, g6_key, g7_key;

	kb_Scan();

	// read keypad data
	g1_key = kb_Data[1];
	g2_key = kb_Data[2];
	g6_key = kb_Data[6];
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
	}
	else if (!press_up) {
		allow_up_press = true;
	}

	if (g6_key & kb_Clear)
		game.exit = true;
}

void main(void)
{
	srand(rtc_Time());
	gfx_Begin( gfx_8bpp );

	extract_tiles();
	// extract_sprites();
	// titleMenu();

	init_game();

	gfx_SetDrawBuffer();

	while (!game.exit)
	{
		handle_keypad();

		updateTerrain();
		updatePlayer();

		gfx_SwapDraw();
	}

	gfx_End();
}