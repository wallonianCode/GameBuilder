#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <array>
#include "Constants.hpp"


const std::string TILESET2 = "pkmnLeafGreenTileset2";
const std::string TILESET_TRAINERS = "trainers";
const std::string TILESET_BRENDAN = "brendan";
const std::string TRAINER_TEST = "trainerExample";
const std::string TILESET_NPCS = "npcLeafGreen";
const int CHAR_WIDTH = 17;
const int Y_NPC = 25;
const int Y_NPC_SMALL = 16;
const int Y_NPC_BIG = 34;
const int Y_NPC_BASE = 43;

enum class Position {FrontLeftFoot, Front, FrontRightFoot, 
BackRightFoot, Back, BackLeftFoot, LeftSideRightFoot, 
LeftSide, LeftSideLeftFoot, RightSideRightFoot,
RightSide, RightSideLeftFoot};

enum class Tile { sand, grass1, grass2, grass3, grass4, wildgrass1, 
flowers1, cuttree1, waterUpLeft1, waterUpCtr1, waterUpRight1, 
waterCtrLeft1, waterCtrCtr1,
waterCtrRight1, waterDownLeft1, waterDownCtr1, waterDownRight1, 
sandRoadNSLeftBorder, sandRoadNSRightBorder, sandRoadLowerLeftCorner,
sandRoadLowerRightCorner, sandRoadWEUpperBorder, sandRoadWELowerBorder,
sandRoadUpperLeftCorner, sandRoadUpperRightCorner, sandUpperLeft, 
sandUpperRight, sandLowerLeft, sandLowerRight, moos, moosRoadNSLeftBorder, 
moosRoadNSRightBorder, moosRoadWEUpperBorder, moosRoadWELowerBorder, 
moosRoadLowerLeftCorner, moosRoadLowerRightCorner, moosRoadUpperLeftCorner, moosRoadUpperRightCorner,
moosUpperRight, moosUpperLeft, moosLowerRight, moosLowerLeft,
mud, mudRoadNSLeftBorder, mudRoadNSRightBorder,
mudRoadWEUpperBorder, mudRoadWELowerBorder, mudRoadLowerLeftCorner,
mudRoadLowerRightCorner, mudRoadUpperLeftCorner, mudRoadUpperRightCorner,
mudUpperRight, mudUpperLeft, mudLowerRight, mudLowerLeft,
borderGrassDownLeft, borderGrassDownCtr, borderGrassDownRight, 
borderGrassLowerRightCorner, borderGrassRightCtr, borderGrassRightUp, 
borderGrassLowerLeftCorner, borderGrassLeftCtr, borderUpperRightCorner, 
borderGrassUpperRightCorner, 
borderLowerLeftCorner, borderLeftCtr, borderDownLeft, borderDownCtr, 
borderDownRight, borderLowerRightCorner, borderRightCtr, borderRightUp,
deepWaterUpLeft, deepWaterUpCtr, deepWaterUpRight, deepWaterCtrLeft,
deepWaterCtrCtr, deepWaterCtrRight, deepWaterDownLeft, deepWaterDownCtr, 
deepWaterDownRight, hugeTreeUpLeft, hugeTreeUpCtr, hugeTreeUpRight, 
hugeTreeCtrLeft1, hugeTreeCtrCtr1, hugeTreeCtrRight1, 
hugeTreeCtrLeft2, hugeTreeCtrCtr2, hugeTreeCtrRight2,
hugeTreeDownLeft, hugeTreeDownCtr, hugeTreeDownRight, bush,
slenderPinTreeUp, slenderPinTreeCtr, slenderPinTreeDown,
pinTreeUpLeft, pinTreeUpRight, pinTreeCtrLeft, pinTreeCtrRight,
pinTreeDownLeft, pinTreeDownRight, brendan, red, flora, blue, chen, 
mama, littleGreenGirl, littlePurpleGirl, fatDude, assistant, 
littleGreenBoy, littlePurpleBoy, oldAdventurer, 
nurse2, littleVioletGirl, womanRedDressBrownHairs, manRedSweatBlueArms, 
manWhiteCollet, oldManBartBald, oldLady, scout, parcEmployeeMale, 
parcEmployeeFemale, mountainer, karateka, rocketMale, rocketFemale};


using sprite = std::pair<Tile, SDL_Rect>;

class TileManager {
public:
	static SDL_Rect get_src(const Tile& tile);
	static int get_background_pixel(const Tile& tile);
	static std::string get_tileset(const Tile& tile);
  static SDL_Rect get_tile_at_mouse_pos();
	static SDL_Rect get_right_tile(const SDL_Rect&);
	static SDL_Rect get_down_tile(const SDL_Rect&);
	static SDL_Rect get_left_tile(const SDL_Rect&);
	static SDL_Rect get_central_tile();
	static int get_tileX_at_x_pos(const int&);
	static int get_tileY_at_y_pos(const int&);
	static bool is_part_of_set(const Tile&);
	static std::array<Tile, 12> get_tiles_huge_tree();
	static std::array<Tile, 6> get_tiles_pin_tree();
	static std::array<Tile, 3> get_tiles_slender_pin_tree();
	static std::string to_string(const Tile& tile);
	static Tile to_tile(const std::string& str);

	
	static SDL_Rect 
	get_character_src_rect(const Tile&, const Position&);
	static SDL_Rect
	get_brendan_src_rect(const Position& pos);

	static Tile get_front_right_foot_tile(const Tile&);
private:
	static std::map<Tile, std::tuple<const std::string&, SDL_Rect, int>> 
	_tileSrc; 

	static std::array<int, 12> _characterRectIndexes;
	static std::array<int, 12> _brendanWalkXIndices;
	static std::array<int, 12> _brendanWalkHIndices;
};


#endif
