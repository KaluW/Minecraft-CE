#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include "mobs.h"

void updateMobs(void) {
	
	spawnMobs();
	handleMobs();
	
}

void spawnMobs() {
	
	/*
	
	Add to a mob array. Probably should be some kind of number cap so if you stay in a chunk to build something,
	your chunk doesn't have 300 or 400 pigs by the time you finished your house
	
	Thinking like 32 mobs, its makeup depending on biome/light
	
	*/
	
}

void handleMobs() {
	
	/*
	
	1. Check Despawn
		- No longer in chunk
		- uninteractice (so if there is a hole underneath you, and you sit in a single chunk building or something,
		there isn't a 100 zombies in that one hole waiting for you to die instantly the moment you stumble into it :P)
		
	2. Draw
	
	3. AI / Trigger Interactions
	
	*/
			
}