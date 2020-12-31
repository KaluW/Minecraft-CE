#ifndef DATA_H
#define DATA_H

#include "defines.h"

#define NO_YIELD			0
#define NO_TOOL				0
#define NO_HARDNESS			0

// Tile Index Definitions (Blocks)
#define AIR 				0
#define STONE 				1
#define GRASS 				2
#define DIRT 				3
#define COBBLESTONE 		4
#define COAL_ORE 			5
#define DIAMOND_ORE 		6
#define GOLD_ORE 			7
#define IRON_ORE 			8
#define BEDROCK 			9
#define OAK_SAPLING 		10
#define OAK_LOG 			11
#define OAK_PLANK			12
#define LEAVES				13
#define SAND				14
#define SANDSTONE			15
#define CACTUS				16
#define CRAFTING_TABLE		17
#define CHEST				18
#define FURNACE				19
#define FURNACE_OFF			19
#define FURNACE_ON			20
#define DEAD_BUSH			21
#define FLOWER_YELLOW		22
#define FLOWER_RED			23
#define FLOWER_PINK			24
#define BED_LEFT_SIDE		25
#define BED_RIGHT_SIDE		26
#define OAK_DOOR_BOTTOM		27
#define OAK_DOOR_TOP		28
#define LADDER				29
#define WATER				30
#define LAVA				31

// Tile Index Definitions (Items)
#define WOODEN_AXE			MAX_BLOCK_TILE_COUNT
#define GOLD_AXE			MAX_BLOCK_TILE_COUNT + 2
#define STONE_AXE			MAX_BLOCK_TILE_COUNT + 3
#define IRON_AXE			MAX_BLOCK_TILE_COUNT + 4
#define DIAMOND_AXE			MAX_BLOCK_TILE_COUNT + 5

#define WOODEN_HOE			MAX_BLOCK_TILE_COUNT + 6
#define GOLD_HOE			MAX_BLOCK_TILE_COUNT + 7
#define STONE_HOE			MAX_BLOCK_TILE_COUNT + 8
#define IRON_HOE			MAX_BLOCK_TILE_COUNT + 9
#define DIAMOND_HOE			MAX_BLOCK_TILE_COUNT + 10

#define WOODEN_PICKAXE		MAX_BLOCK_TILE_COUNT + 11
#define GOLD_PICKAXE		MAX_BLOCK_TILE_COUNT + 12
#define STONE_PICKAXE		MAX_BLOCK_TILE_COUNT + 13
#define IRON_PICKAXE		MAX_BLOCK_TILE_COUNT + 14
#define DIAMOND_PICKAXE		MAX_BLOCK_TILE_COUNT + 15

#define WOODEN_SHOVEL		MAX_BLOCK_TILE_COUNT + 16
#define GOLD_SHOVEL			MAX_BLOCK_TILE_COUNT + 17
#define STONE_SHOVEL		MAX_BLOCK_TILE_COUNT + 18
#define IRON_SHOVEL			MAX_BLOCK_TILE_COUNT + 19
#define DIAMOND_SHOVEL		MAX_BLOCK_TILE_COUNT + 20

#define WOODEN_SWORD		MAX_BLOCK_TILE_COUNT + 21
#define GOLD_SWORD			MAX_BLOCK_TILE_COUNT + 22
#define STONE_SWORD			MAX_BLOCK_TILE_COUNT + 23
#define IRON_SWORD			MAX_BLOCK_TILE_COUNT + 24
#define DIAMOND_SWORD		MAX_BLOCK_TILE_COUNT + 25

#define SHEARS				MAX_BLOCK_TILE_COUNT + 26

#define BED					MAX_BLOCK_TILE_COUNT + 27
#define OAK_DOOR 			MAX_BLOCK_TILE_COUNT + 28

enum tools { None, Axe, Pickaxe, Shovel, Shears };

typedef struct {
	
	uint8_t yield; // Index of the item that it gives you when you break it.
	uint8_t required_tool; // Required tool to successfully harvest item
	enum tools best_tool; // e.g. sand - shovel, cobwebs - shears
	uint8_t hardness; // 0 (instant breaking) - 255 (obsidian)
	
	void (*onClick)(void); // Trigger specific action if interacted with
	void (*onUpdate)(void); // Trigger specific action every time map updates itself
	
} block_t;

extern block_t blocks[MAX_BLOCK_TILE_COUNT];

void bed_onClick(void);
void chest_onClick(void);
void craftingTable_onClick(void);
void deadBush_onClick(void);
void door_onClick(void);
void equalToolEffic_onClick(void);
void furnace_onClick(void);
void lava_onClick(void);
void water_onClick(void);

void gravityBlock_onUpdate(void);
void lava_onUpdate(void);
void water_onUpdate(void);
void waterPresence_onUpdate(void);

#endif