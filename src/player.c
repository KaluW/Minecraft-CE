#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include "player.h"

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


void updatePlayer() {
	
	/*
	
	1. Update controls
	
	2. Draw
	
	3. Trigger interaction w/ terrain
		- Land/Water
		- Falling/Jumping/Swimming
		- Building/Destroying blocks
			- Update inventory
	
	4. Trigger interaction w/ mob
	
	*/
}