#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include "data.h"

// dead bushes are interesting. Treat it like a sheep, and it will drop a dead bush, otherwise 0-2 sticks. Baaaaa Baaaa Black Sheep...
// Plants can be washed away by water
// Need a BED entity, b/c I can't use BED_LEFT_SIDE or BED_RIGHT_SIDE to describe the bed as a whole :P
// Make sure to take care of both halves of an object if they take up more than one tile (beds, doors, etc.)

block_t blocks[MAX_BLOCK_TILE_COUNT] = {
	
//	 (Single) Yield		Required Tool			Best Tool		Hardness		onClick						onUpdate			
	{ NO_YIELD,			NO_TOOL,				None,			NO_HARDNESS,	NULL,						NULL					}, // AIR
	{ COBBLESTONE,		WOODEN_PICKAXE,			Pickaxe,		10,				NULL,						NULL					}, // STONE
	{ DIRT,				NO_TOOL,				Shovel,			3,				NULL,						NULL					}, // GRASS
	{ DIRT,				NO_TOOL,				Shovel,			2,				NULL,						NULL					}, // DIRT
	{ COBBLESTONE,		WOODEN_PICKAXE,			Pickaxe,		10,				NULL,						NULL					}, // COBBLESTONE
	{ COAL_ORE,			WOODEN_PICKAXE,			Pickaxe,		15,				NULL,						NULL					}, // COAL_ORE
	{ DIAMOND_ORE,		IRON_PICKAXE,			Pickaxe,		15,				NULL,						NULL					}, // DIAMOND_ORE
	{ GOLD_ORE,			IRON_PICKAXE,			Pickaxe,		15,				NULL,						NULL					}, // GOLD_ORE
	{ IRON_ORE,			STONE_PICKAXE,			Pickaxe,		15,				NULL,						NULL					}, // IRON_ORE
	{ NO_YIELD,			NO_TOOL,				None,			NO_HARDNESS,	NULL,						NULL					}, // BEDROCK
	{ OAK_SAPLING,		NO_TOOL,				None,			NO_HARDNESS,	NULL,						NULL					}, // OAK_SAPLING
	{ OAK_LOG,			NO_TOOL,				Axe,			10,				NULL,						NULL					}, // OAK_LOG
	{ OAK_PLANK,		NO_TOOL,				Axe,			10,				NULL,						NULL					}, // OAK_PLANK
	{ LEAVES,			SHEARS,					Shears,			1,				NULL,						NULL					}, // LEAVES
	{ SAND,				NO_TOOL,				None,			2,				NULL,						gravityBlock_onUpdate	}, // SAND
	{ SANDSTONE,		WOODEN_PICKAXE,			Pickaxe,		4,				NULL,						NULL					}, // SANDSTONE
	{ CACTUS,			NO_TOOL,				None,			3,				equalEfficiency_onClick,	NULL					}, // CACTUS
	{ CRAFTING_TABLE,	NO_TOOL,				Axe,			12,				craftingTable_onClick,		NULL					}, // CRAFTING_TABLE
	{ CHEST,			NO_TOOL,				Axe,			21,				chest_onClick,				NULL					}, // CHEST
	{ FURNACE,			WOODEN_PICKAXE,			Pickaxe,		17,				furnace_onClick,			NULL					}, // FURNACE_OFF
	{ FURNACE,			WOODEN_PICKAXE,			Pickaxe,		17,				furnace_onClick,			NULL					}, // FURNACE_ON
	{ NO_YIELD,			NO_TOOL,				None,			NO_HARDNESS,	deadBush_onClick,			NULL					}, // DEAD_BUSH
	{ FLOWER_YELLOW,	NO_TOOL,				None,			NO_HARDNESS,	NULL,						waterPresence_onUpdate	}, // FLOWER_YELLOW
	{ FLOWER_RED,		NO_TOOL,				None,			NO_HARDNESS,	NULL,						waterPresence_onUpdate	}, // FLOWER_RED
	{ FLOWER_PINK,		NO_TOOL,				None,			NO_HARDNESS,	NULL,						waterPresence_onUpdate	}, // FLOWER_PINK
	{ BED,				NO_TOOL,				None,			1,				bed_onClick,				NULL					}, // BED_LEFT_SIDE
	{ BED,				NO_TOOL,				None,			1,				bed_onClick,				NULL					}, // BED_RIGHT_SIDE
	{ OAK_DOOR,			NO_TOOL,				Axe,			15,				door_onClick,				NULL					}, // OAK_DOOR_BOTTOM
	{ OAK_DOOR,			NO_TOOL,				Axe,			15,				door_onClick,				NULL					}, // OAK_DOOR_TOP
	{ LADDER,			NO_TOOL,				Axe,			2,				NULL,						NULL					}, // LADDER
	{ NO_YIELD,			NO_TOOL,				None,			NO_HARDNESS,	water_onClick,				water_onUpdate			}, // WATER
	{ NO_YIELD,			NO_TOOL,				None,			NO_HARDNESS,	lava_onClick,				lava_onUpdate			} // LAVA
	
};



void bed_onClick(void) { }
void chest_onClick(void) { }
void craftingTable_onClick(void) { }
void deadBush_onClick(void) { }
void door_onClick(void) { }
void equalEfficiency_onClick(void) { }
void furnace_onClick(void) { }
void lava_onClick(void) { }
void water_onClick(void) { }

void gravityBlock_onUpdate(void) { }
void lava_onUpdate(void) { }
void water_onUpdate(void) { }
void waterPresence_onUpdate(void) {	}
