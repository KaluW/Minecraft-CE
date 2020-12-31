#include "data.h"

// dead bushes are interesting. Treat it like a sheep, and it will drop a dead bush, otherwise 0-2 sticks. Baaaaa Baaaa Black Sheep...
// Plants can be washed away by water
// Need a BED entity, b/c I can't use BED_LEFT_SIDE or BED_RIGHT_SIDE to describe the bed as a whole :P
// Make sure to take care of both halves of an object if they take up more than one tile (beds, doors, etc.)


block_t blocks[MAX_BLOCK_TILE_COUNT] = {
	
	[AIR]   			= { .yield = NO_YIELD, 			.required_tool = NO_TOOL, 			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = NULL, 					.onUpdate = NULL 					},
	[STONE]   			= { .yield = COBBLESTONE, 		.required_tool = WOODEN_PICKAXE,	.best_tool = Pickaxe, 	.hardness = 10, 			.onClick = NULL, 					.onUpdate = NULL 					},
	[GRASS]				= { .yield = DIRT, 				.required_tool = NO_TOOL, 			.best_tool = Shovel, 	.hardness = 3, 				.onClick = NULL, 					.onUpdate = NULL 					},
	[DIRT]				= { .yield = DIRT, 				.required_tool = NO_TOOL, 			.best_tool = Shovel, 	.hardness = 2,				.onClick = NULL, 					.onUpdate = NULL 					},
	[COBBLESTONE]		= { .yield = COBBLESTONE, 		.required_tool = WOODEN_PICKAXE,	.best_tool = Pickaxe, 	.hardness = 10, 			.onClick = NULL, 					.onUpdate = NULL 					},
	[COAL_ORE]			= { .yield = COAL_ORE, 			.required_tool = WOODEN_PICKAXE,	.best_tool = Pickaxe, 	.hardness = 15, 			.onClick = NULL, 					.onUpdate = NULL 					},
	[DIAMOND_ORE]		= { .yield = DIAMOND_ORE, 		.required_tool = IRON_PICKAXE, 		.best_tool = Pickaxe, 	.hardness = 15, 			.onClick = NULL, 					.onUpdate = NULL 					},
	[GOLD_ORE]			= { .yield = GOLD_ORE, 			.required_tool = IRON_PICKAXE, 		.best_tool = Pickaxe, 	.hardness = 15, 			.onClick = NULL, 					.onUpdate = NULL 					},
	[IRON_ORE]			= { .yield = IRON_ORE, 			.required_tool = STONE_PICKAXE, 	.best_tool = Pickaxe, 	.hardness = 15, 			.onClick = NULL, 					.onUpdate = NULL 					},
	[BEDROCK]			= { .yield = NO_YIELD, 			.required_tool = NO_TOOL, 			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = NULL, 					.onUpdate = NULL 					},
	[OAK_SAPLING]		= { .yield = OAK_SAPLING, 		.required_tool = NO_TOOL, 			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = NULL, 					.onUpdate = NULL 					},
	[OAK_LOG]			= { .yield = OAK_LOG, 			.required_tool = NO_TOOL, 			.best_tool = Axe, 		.hardness = 10, 			.onClick = NULL, 					.onUpdate = NULL 					},
	[OAK_PLANK]			= { .yield = OAK_PLANK, 		.required_tool = NO_TOOL, 			.best_tool = Axe, 		.hardness = 10, 			.onClick = NULL, 					.onUpdate = NULL 					},
	[LEAVES]			= { .yield = LEAVES, 			.required_tool = SHEARS, 			.best_tool = Shears, 	.hardness = 1, 				.onClick = NULL, 					.onUpdate = NULL 					},
	[SAND]				= { .yield = SAND, 				.required_tool = NO_TOOL, 			.best_tool = Shovel, 	.hardness = 2, 				.onClick = NULL, 					.onUpdate = gravityBlock_onUpdate 	},
	[SANDSTONE]			= { .yield = SANDSTONE, 		.required_tool = WOODEN_PICKAXE,	.best_tool = Pickaxe, 	.hardness = 4, 				.onClick = NULL, 					.onUpdate = NULL 					},
	[CACTUS]			= { .yield = CACTUS, 			.required_tool = NO_TOOL,			.best_tool = None, 		.hardness = 3, 				.onClick = equalToolEffic_onClick, 	.onUpdate = NULL					},
	[CRAFTING_TABLE]	= { .yield = CRAFTING_TABLE,	.required_tool = NO_TOOL, 			.best_tool = Axe, 		.hardness = 12, 			.onClick = craftingTable_onClick, 	.onUpdate = NULL 					},
	[CHEST]				= { .yield = CHEST, 			.required_tool = NO_TOOL, 			.best_tool = Axe, 		.hardness = 21, 			.onClick = chest_onClick, 			.onUpdate = NULL					},
	[FURNACE_OFF]		= { .yield = FURNACE, 			.required_tool = WOODEN_PICKAXE,	.best_tool = Pickaxe, 	.hardness = 17, 			.onClick = furnace_onClick,			.onUpdate = NULL 					},
	[FURNACE_ON]		= { .yield = FURNACE, 			.required_tool = WOODEN_PICKAXE,	.best_tool = Pickaxe, 	.hardness = 17, 			.onClick = furnace_onClick, 		.onUpdate = NULL 					},
	[DEAD_BUSH]			= { .yield = NO_YIELD, 			.required_tool = NO_TOOL, 			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = deadBush_onClick, 		.onUpdate = NULL 					},
	[FLOWER_YELLOW]		= { .yield = FLOWER_YELLOW, 	.required_tool = NO_TOOL,			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = NULL, 					.onUpdate = waterPresence_onUpdate 	},
	[FLOWER_RED]		= { .yield = FLOWER_RED, 		.required_tool = NO_TOOL,			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = NULL, 					.onUpdate = waterPresence_onUpdate 	},
	[FLOWER_PINK]		= { .yield = FLOWER_PINK,		.required_tool = NO_TOOL,			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = NULL, 					.onUpdate = waterPresence_onUpdate 	},
	[BED_LEFT_SIDE]		= { .yield = BED,				.required_tool = NO_TOOL,			.best_tool = None, 		.hardness = 1,				.onClick = bed_onClick, 			.onUpdate = NULL 					},
	[BED_RIGHT_SIDE]	= { .yield = BED,				.required_tool = NO_TOOL,			.best_tool = None, 		.hardness = 1,				.onClick = bed_onClick, 			.onUpdate = NULL 					},
	[OAK_DOOR_BOTTOM]	= { .yield = OAK_DOOR,			.required_tool = NO_TOOL,			.best_tool = Axe, 		.hardness = 15,				.onClick = door_onClick, 			.onUpdate = NULL 					},
	[OAK_DOOR_TOP]		= { .yield = OAK_DOOR,			.required_tool = NO_TOOL,			.best_tool = Axe, 		.hardness = 15,				.onClick = door_onClick, 			.onUpdate = NULL 					},
	[LADDER]			= { .yield = LADDER,			.required_tool = NO_TOOL,			.best_tool = Axe, 		.hardness = 2,				.onClick = NULL, 					.onUpdate = NULL 					},
	[WATER]				= { .yield = NO_YIELD,			.required_tool = NO_TOOL,			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = water_onClick, 			.onUpdate = water_onUpdate 			},
	[LAVA]				= { .yield = NO_YIELD,			.required_tool = NO_TOOL,			.best_tool = None, 		.hardness = NO_HARDNESS,	.onClick = lava_onClick, 			.onUpdate = lava_onUpdate 			}
	
};


void bed_onClick(void) { }
void chest_onClick(void) { }
void craftingTable_onClick(void) { }
void deadBush_onClick(void) { }
void door_onClick(void) { }
void equalToolEffic_onClick(void) { }
void furnace_onClick(void) { }
void lava_onClick(void) { }
void water_onClick(void) { }

void gravityBlock_onUpdate(void) { }
void lava_onUpdate(void) { }
void water_onUpdate(void) { }
void waterPresence_onUpdate(void) {	}