#include "../Headers/Tile.hpp"


std::map<Tile, std::tuple<const std::string&, SDL_Rect, int>> 
TileManager::_tileSrc = {
	{Tile::sand, {TILESET2, {2, 2, S-2, S-2}, 5}},
	{Tile::grass1, {TILESET2, {6*S+2, 2, S-3, S-3}, 10}},
	{Tile::grass2, {TILESET2, {6*S+2, S+2, S-3, S-3}, 2}},
	{Tile::grass3, {TILESET2, {6*S+2, 2*S+2, S-3, S-3}, 2}},
	{Tile::grass4, {TILESET2, {7*S+2, S+2, S-3, S-3}, 2}},
	{Tile::wildgrass1, {TILESET2, {7*S+2, 2, S-2, S-2}, 2}},
	{Tile::flowers1, {TILESET2, {7*S+1, 2*S+2, S-2, S-2}, 2}},
	{Tile::cuttree1, {TILESET2, {8*S+1, 1, S-1, S-1}, 2}},
	{Tile::waterUpLeft1, {TILESET2, {10*S+1, 1, S-3, S-3}, 10}},
	{Tile::waterUpCtr1, {TILESET2, {11*S+2, 1, S-3, S-3}, 10}},
	{Tile::waterUpRight1, {TILESET2, {12*S+2, 1, S-2, S-3}, 20}},
	{Tile::waterCtrLeft1, {TILESET2, {10*S+1, S+2, S-3, S-3}, 10}},
	{Tile::waterCtrCtr1, {TILESET2, {11*S+2, S+2, S-3, S-3}, 10}},
	{Tile::waterCtrRight1, {TILESET2, {12*S+2, S+2, S-2, S-3}, 2}},
	{Tile::waterDownLeft1, {TILESET2, {10*S+1, 2*S+2, S-3, S-2}, 10}},
	{Tile::waterDownCtr1, {TILESET2, {11*S+2, 2*S+2, S-3, S-2}, 10}},
	{Tile::waterDownRight1, {TILESET2, {12*S+2, 2*S+2, S-2, S-2}, 2}},
	{Tile::sandRoadNSLeftBorder, {TILESET2, {S+2, 2, S-3, S-3}, 1}},
	{Tile::sandRoadNSRightBorder, {TILESET2, {2*S+2, 2, S-3, S-3}, 1}},
  {Tile::sandRoadWEUpperBorder, {TILESET2, {3*S+2, 2, S-3, S-3}, 1}},
	{Tile::sandRoadWELowerBorder, {TILESET2, {4*S+2, 2, S-3, S-3}, 1}},
	{Tile::sandRoadLowerLeftCorner, {TILESET2, {S+2, S+2, S-3, S-3}, 1}},
	{Tile::sandRoadLowerRightCorner, {TILESET2, {2*S+2, S+2, S-3, S-3}, 1}},
	{Tile::sandRoadUpperLeftCorner, {TILESET2, {3*S+2, S+2, S-3, S-3}, 1}},
	{Tile::sandRoadUpperRightCorner, {TILESET2, {4*S+2, S+2, S-3, S-3}, 1}},
	{Tile::sandUpperLeft, {TILESET2, {S+2, 2*S+2, S-3, S-3}, 1}},
	{Tile::sandUpperRight, {TILESET2, {2*S+2, 2*S+2, S-3, S-3}, 1}},
	{Tile::sandLowerLeft, {TILESET2, {3*S+2, 2*S+2, S-3, S-3}, 1}},
	{Tile::sandLowerRight, {TILESET2, {4*S+2, 2*S+2, S-3, S-3}, 1}},
	{Tile::moos, {TILESET2, {2, 3*S+2, S-3, S-3}, 1}},
	{Tile::moosRoadNSLeftBorder, {TILESET2, {S+2, 3*S+2, S-3, S-3}, 1}},
	{Tile::moosRoadNSRightBorder, {TILESET2, {2*S+2, 3*S+2, S-3, S-3}, 1}},
	{Tile::moosRoadWEUpperBorder, {TILESET2, {3*S+2, 3*S+2, S-3, S-3}, 1}},
	{Tile::moosRoadWELowerBorder, {TILESET2, {4*S+2, 3*S+2, S-3, S-3}, 1}},
	{Tile::moosRoadLowerLeftCorner, {TILESET2, {S+2, 4*S+2, S-3, S-3}, 1}},
	{Tile::moosRoadLowerRightCorner, 
	{TILESET2, {2*S+2, 4*S+2, S-3, S-3}, 1}},
	{Tile::moosRoadUpperLeftCorner, 
	{TILESET2, {3*S+2, 4*S+2, S-3, S-3}, 1}},
	{Tile::moosRoadUpperRightCorner, 
	{TILESET2, {4*S+2, 4*S+2, S-3, S-3}, 1}},
	{Tile::moosUpperRight, {TILESET2, {S+2, 5*S+2, S-3, S-3}, 1}},
	{Tile::moosUpperLeft, {TILESET2, {2*S+2, 5*S+2, S-3, S-3}, 1}},
	{Tile::moosLowerLeft, {TILESET2, {3*S+2, 5*S+2, S-3, S-3}, 1}},
	{Tile::moosLowerRight, {TILESET2, {4*S+2, 5*S+2, S-3, S-3}, 1}},	
	{Tile::mud, {TILESET2, {2, 6*S+2, S-3, S-3}, 1}},
	{Tile::mudRoadNSLeftBorder, {TILESET2, {S+2, 6*S+2, S-3, S-3}, 1}},
	{Tile::mudRoadNSRightBorder, {TILESET2, {2*S+2, 6*S+2, S-3, S-3}, 1}},
	{Tile::mudRoadWEUpperBorder, {TILESET2, {3*S+2, 6*S+2, S-3, S-3}, 1}},
	{Tile::mudRoadWELowerBorder, {TILESET2, {4*S+2, 6*S+2, S-3, S-3}, 1}},
	{Tile::mudRoadLowerLeftCorner, {TILESET2, {S+2, 7*S+2, S-3, S-3}, 1}},
	{Tile::mudRoadLowerRightCorner, 
	{TILESET2, {2*S+2, 7*S+2, S-3, S-3}, 1}},
	{Tile::mudRoadUpperLeftCorner, 
	{TILESET2, {3*S+2, 7*S+2, S-3, S-3}, 1}},
	{Tile::mudRoadUpperRightCorner, 
	{TILESET2, {4*S+2, 7*S+2, S-3, S-3}, 1}},
	{Tile::mudUpperRight, {TILESET2, {S+2, 8*S+2, S-3, S-3}, 1}},
	{Tile::mudUpperLeft, {TILESET2, {2*S+2, 8*S+2, S-3, S-3}, 1}},
	{Tile::mudLowerLeft, {TILESET2, {3*S+2, 8*S+2, S-3, S-3}, 1}},
	{Tile::mudLowerRight, {TILESET2, {4*S+2, 8*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassDownLeft, {TILESET2, {6*S+2, 4*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassDownCtr, {TILESET2, {7*S+2, 4*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassDownRight, {TILESET2, {8*S+2, 4*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassLowerRightCorner, 
	{TILESET2, {6*S+2, 5*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassRightCtr, {TILESET2, {7*S+2, 5*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassRightUp, {TILESET2, {8*S+2, 5*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassLowerLeftCorner, 
	{TILESET2, {6*S+2, 6*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassLeftCtr, {TILESET2, {7*S+2, 6*S+2, S-3, S-3}, 1}},
	{Tile::borderUpperRightCorner, {TILESET2, {8*S+2, 6*S+2, S-3, S-3}, 1}},
	{Tile::borderGrassUpperRightCorner, 
	{TILESET2, {6*S+2, 7*S+2, S-3, S-3}, 1}},
	{Tile::borderLowerLeftCorner, {TILESET2, {7*S+2, 7*S+2, S-3, S-3}, 1}},
	{Tile::borderLeftCtr, {TILESET2, {8*S+2, 7*S+2, S-3, S-3}, 1}},
	{Tile::borderDownLeft, {TILESET2, {6*S+2, 8*S+2, S-3, S-3}, 1}},
	{Tile::borderDownCtr, {TILESET2, {7*S+2, 8*S+2, S-3, S-3}, 1}},
	{Tile::borderDownRight, {TILESET2, {8*S+2, 8*S+2, S-3, S-3}, 1}},
	{Tile::borderLowerRightCorner, {TILESET2, {6*S+2, 9*S+2, S-3, S-3}, 1}},
	{Tile::borderRightCtr, {TILESET2, {7*S+2, 9*S+2, S-3, S-3}, 1}},
	{Tile::borderRightUp, {TILESET2, {8*S+2, 9*S+2, S-3, S-3}, 1}},
	{Tile::deepWaterUpLeft, {TILESET2, {10*S+1, 4*S+1, S-3, S-3}, 1}},
	{Tile::deepWaterUpCtr, {TILESET2, {11*S+2, 4*S+1, S-3, S-3}, 1}},
	{Tile::deepWaterUpRight, {TILESET2, {12*S+2, 4*S+1, S-2, S-3}, 1}},
	{Tile::deepWaterCtrLeft, {TILESET2, {10*S+1, 5*S+2, S-3, S-3}, 1}},
	{Tile::deepWaterCtrCtr, {TILESET2, {11*S+2, 5*S+2, S-3, S-3}, 1}},
	{Tile::deepWaterCtrRight, {TILESET2, {12*S+2, 5*S+2, S-2, S-3}, 1}},
	{Tile::deepWaterDownLeft, {TILESET2, {10*S+1, 6*S+2, S-3, S-2}, 1}},
	{Tile::deepWaterDownCtr, {TILESET2, {11*S+2, 6*S+2, S-3, S-2}, 1}},
	{Tile::deepWaterDownRight, {TILESET2, {12*S+2, 6*S+2, S-2, S-2}, 1}},
	{Tile::hugeTreeUpLeft, {TILESET2, {14*S+2, 2, S-3, S-2}, 1}},
	{Tile::hugeTreeUpCtr, {TILESET2, {15*S+2, 2, S-3, S-2}, 1}},
	{Tile::hugeTreeUpRight, {TILESET2, {16*S+2, 2, S-3, S-2}, 1}},
	{Tile::hugeTreeCtrLeft1, {TILESET2, {14*S+2, S+1, S-3, S-2}, 1}},
	{Tile::hugeTreeCtrCtr1, {TILESET2, {15*S+2, S+1, S-3, S-2}, 1}},
	{Tile::hugeTreeCtrRight1, {TILESET2, {16*S+2, S+1, S-3, S-2}, 1}},
	{Tile::hugeTreeCtrLeft2, {TILESET2, {14*S+2, 2*S+1, S-3, S-2}, 1}},
	{Tile::hugeTreeCtrCtr2, {TILESET2, {15*S+2, 2*S+1, S-3, S-2}, 1}},
	{Tile::hugeTreeCtrRight2, {TILESET2, {16*S+2, 2*S+1, S-3, S-2}, 1}},
	{Tile::hugeTreeDownLeft, {TILESET2, {14*S+2, 3*S+1, S-3, S-3}, 1}},
	{Tile::hugeTreeDownCtr, {TILESET2, {15*S+2, 3*S+1, S-3, S-3}, 1}},
	{Tile::hugeTreeDownRight, {TILESET2, {16*S+2, 3*S+1, S-3, S-3}, 1}},
	{Tile::bush, {TILESET2, {17*S+1, 2, S-1, S-2}, 1}},
	{Tile::slenderPinTreeUp, {TILESET2, {17*S+1, 13*S+2, S-1, S-3}, 1}},
	{Tile::slenderPinTreeCtr, {TILESET2, {17*S+1, 14*S+2, S-1, S-3}, 1}},
	{Tile::slenderPinTreeDown, {TILESET2, {17*S+1, 15*S+2, S-1, S-3}, 1}},
	{Tile::pinTreeUpLeft, {TILESET2, {14*S+2, 17*S+2, S-3, S-3}, 1}},
	{Tile::pinTreeUpRight, {TILESET2, {15*S+2, 17*S+2, S-3, S-3}, 1}},
	{Tile::pinTreeCtrLeft, {TILESET2, {14*S+2, 18*S+2, S-3, S-3}, 1}},
	{Tile::pinTreeCtrRight, {TILESET2, {15*S+2, 18*S+2, S-3, S-3}, 1}},
	{Tile::pinTreeDownLeft, {TILESET2, {14*S+2, 19*S+1, S-3, S-3}, 1}},
	{Tile::pinTreeDownRight, {TILESET2, {15*S+2, 19*S+1, S-3, S-3}, 1}},
	{Tile::brendan, {TILESET_BRENDAN, {T, T, S, S+3}, 1}},
	{Tile::red, {TILESET_NPCS, {9, Y_NPC_BASE, 15, 23}, 1}},
	{Tile::flora, {TILESET_NPCS, {9, Y_NPC_BASE + Y_NPC, 15, 23}, 1}},
	{Tile::blue, {TILESET_NPCS, {9, Y_NPC_BASE + 2*Y_NPC, 15, 23}, 1}}, 
	{Tile::chen, {TILESET_NPCS, {9, Y_NPC_BASE + 3*Y_NPC, 15, 23}, 1}}, 
	{Tile::mama, {TILESET_NPCS, {9, Y_NPC_BASE + 4*Y_NPC, 15, 23}, 1}}, 
	{Tile::littleGreenGirl, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 5*Y_NPC, 15, 23}, 1}}, 
	{Tile::littlePurpleGirl, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 6*Y_NPC, 15, 23}, 1}}, 
	{Tile::fatDude, {TILESET_NPCS, {9, Y_NPC_BASE + 7*Y_NPC, 15, 23}, 1}}, 
	{Tile::assistant, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 8*Y_NPC, 15, 23}, 1}}, 
	{Tile::littleGreenBoy, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 9*Y_NPC, 15, 23}, 1}}, 
	{Tile::littlePurpleBoy, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 10*Y_NPC, 15, 23}, 1}}, 
	{Tile::oldAdventurer, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 11*Y_NPC, 15, 23}, 1}}, 
	{Tile::nurse2, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 14*Y_NPC, 15, 23}, 1}}, 
	{Tile::littleVioletGirl,
	{TILESET_NPCS, {9, Y_NPC_BASE + 18*Y_NPC, 15, 23}, 1}},
	{Tile::womanRedDressBrownHairs,
	{TILESET_NPCS, {9, Y_NPC_BASE + 19*Y_NPC, 15, 23}, 1}},
	{Tile::manRedSweatBlueArms, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 20*Y_NPC, 15, 23}, 1}},
	{Tile::manWhiteCollet, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 24*Y_NPC, 15, 23}, 1}},
	{Tile::oldManBartBald, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 26*Y_NPC + Y_NPC_BIG, 15, 23}, 1}},
	{Tile::oldLady,
	{TILESET_NPCS, {9, Y_NPC_BASE + 28*Y_NPC + Y_NPC_BIG, 15, 23}, 1}},
	{Tile::scout, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 29*Y_NPC + Y_NPC_BIG, 15, 23}, 1}},
	{Tile::parcEmployeeMale,
	{TILESET_NPCS, {9, Y_NPC_BASE + 30*Y_NPC + Y_NPC_BIG, 15, 23}, 1}},
	{Tile::parcEmployeeFemale,
	{TILESET_NPCS, {9, Y_NPC_BASE + 31*Y_NPC + Y_NPC_BIG, 15, 23}, 1}},
	{Tile::mountainer,
	{TILESET_NPCS, {9, Y_NPC_BASE + 32*Y_NPC + Y_NPC_BIG, 15, 23}, 1}},
	{Tile::karateka, 
	{TILESET_NPCS, {9, Y_NPC_BASE + 33*Y_NPC + Y_NPC_BIG, 
	15, 23}, 1}},
  {Tile::rocketMale,
	{TILESET_NPCS, 
	{9, Y_NPC_BASE + 40*Y_NPC + Y_NPC_BIG + 2*Y_NPC_SMALL, 15, 23}, 1}},
	{Tile::rocketFemale,
	{TILESET_NPCS, 
	{9, Y_NPC_BASE + 41*Y_NPC + Y_NPC_BIG + 2*Y_NPC_SMALL, 15, 23}, 1}}	
};


std::array<int, 12> TileManager::_characterRectIndexes = 
{0, CHAR_WIDTH, 2*CHAR_WIDTH, 3*CHAR_WIDTH, 4*CHAR_WIDTH, 
5*CHAR_WIDTH, 6*CHAR_WIDTH, 7*CHAR_WIDTH, 8*CHAR_WIDTH, 9*CHAR_WIDTH, 
10*CHAR_WIDTH, 11*CHAR_WIDTH};


std::array<int, 12> TileManager::_brendanWalkXIndices = 
{34, 0, 16, 85, 51, 67, 171, 153, 189, 136, 104, 119};


std::array<int, 12> TileManager::_brendanWalkHIndices =
{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};


std::string TileManager::get_tileset(const Tile& tile) {
	return std::get<0>(_tileSrc.at(tile));
}


SDL_Rect TileManager::get_src(const Tile& tile) {
	return std::get<1>(_tileSrc.at(tile));
}


int TileManager::get_background_pixel(const Tile& tile) {
	return std::get<2>(_tileSrc.at(tile));
}


SDL_Rect TileManager::get_tile_at_mouse_pos() {
  int x, y;
	SDL_GetMouseState(&x, &y);
	x -= (x % (4*S));
	y -= (y % (4*S));
	return {x, y, 4*S, 4*S};
}


SDL_Rect TileManager::get_right_tile(const SDL_Rect& pos) {
	return {pos.x + 4*S, pos.y, pos.w, pos.h};
}


SDL_Rect TileManager::get_down_tile(const SDL_Rect& pos) {
	return {pos.x, pos.y + 4*S, pos.w, pos.h};
}


SDL_Rect TileManager::get_left_tile(const SDL_Rect& pos) {
	return {pos.x - 4*S, pos.y, pos.w, pos.h};
}


SDL_Rect TileManager::get_central_tile() {
	return {get_tileX_at_x_pos(WINDOW_WIDTH / 2), 
					get_tileY_at_y_pos(WINDOW_HEIGHT / 2), 4*S, 4*S};
}


int TileManager::get_tileX_at_x_pos(const int& x) {
	return (x - (x % (4*S)));
}


int TileManager::get_tileY_at_y_pos(const int& y) {
	return (y - (y % (4*S)));
}


bool TileManager::is_part_of_set(const Tile& tile) {
	return ((tile == Tile::hugeTreeUpLeft) 
	|| (tile == Tile::hugeTreeUpCtr)
	|| (tile == Tile::hugeTreeUpRight) 
	|| (tile == Tile::hugeTreeCtrLeft1) 
	|| (tile == Tile::hugeTreeCtrCtr1) 
	|| (tile == Tile::hugeTreeCtrRight1) 	
	|| (tile == Tile::hugeTreeCtrLeft2) 
	|| (tile == Tile::hugeTreeCtrCtr2) 
	|| (tile == Tile::hugeTreeCtrRight2)
	|| (tile == Tile::hugeTreeDownLeft) 
	|| (tile == Tile::hugeTreeDownCtr) 
	|| (tile == Tile::hugeTreeDownRight) 
  || (tile == Tile::slenderPinTreeUp) 
	|| (tile == Tile::slenderPinTreeCtr) 
	|| (tile == Tile::slenderPinTreeDown) 
	|| (tile == Tile::pinTreeUpLeft) 
	|| (tile == Tile::pinTreeUpRight) 
	|| (tile == Tile::pinTreeCtrLeft) 
	|| (tile == Tile::pinTreeCtrRight)
	|| (tile == Tile::pinTreeDownLeft) 
	|| (tile == Tile::pinTreeDownRight));
}


std::array<Tile, 12> TileManager::get_tiles_huge_tree() {
	return {Tile::hugeTreeUpLeft, Tile::hugeTreeUpCtr, 
	Tile::hugeTreeUpRight, Tile::hugeTreeCtrLeft1, Tile::hugeTreeCtrCtr1, 
	Tile::hugeTreeCtrRight1, Tile::hugeTreeCtrLeft2, Tile::hugeTreeCtrCtr2,
	Tile::hugeTreeCtrRight2, Tile::hugeTreeDownLeft, Tile::hugeTreeDownCtr,
	Tile::hugeTreeDownRight};
}


std::array<Tile, 6> TileManager::get_tiles_pin_tree() {
	return {Tile::pinTreeUpLeft, Tile::pinTreeUpRight, 
	Tile::pinTreeCtrLeft, Tile::pinTreeCtrRight,
	Tile::pinTreeDownLeft, Tile::pinTreeDownRight};
}


std::array<Tile, 3> TileManager::get_tiles_slender_pin_tree() {
	return { Tile::slenderPinTreeUp, Tile::slenderPinTreeCtr, 
	Tile::slenderPinTreeDown};
}



std::string TileManager::to_string(const Tile& tile) {
	switch(tile) {
		case Tile::sand: return "sand";
		case Tile::grass1: return "grass1"; 
		case Tile::grass2: return "grass2"; 
		case Tile::grass3: return "grass3";
		case Tile:: grass4: return "grass4"; 
		case Tile::wildgrass1: return "wildgrass1";
 		case Tile::flowers1: return "flowers1"; 
		case Tile::cuttree1: return "cuttree1"; 
		case Tile::waterUpLeft1: return "waterUpLeft1";
		case Tile::waterUpCtr1: return "waterUpCtr1";
		case Tile::waterUpRight1: return "waterUpRight1"; 
		case Tile::waterCtrLeft1: return "waterCtrLeft1";
		case Tile::waterCtrCtr1: return "waterCtrCtr1"; 
		case Tile::waterCtrRight1: return "waterCtrRight1"; 
		case Tile::waterDownLeft1: return "waterDownLeft1";
		case Tile::waterDownCtr1: return "waterDownCtr1"; 
		case Tile::waterDownRight1: return "waterDownRight1"; 
		case Tile::sandRoadNSLeftBorder: return "sandRoadNSLeftBorder";
		case Tile::sandRoadNSRightBorder: return "sandRoadNSRightBorder";
		case Tile::sandRoadLowerLeftCorner: return "sandRoadLowerLeftCorner";
 		case Tile::sandRoadLowerRightCorner: 
			return "sandRoadLowerRightCorner";
		case Tile::sandRoadWEUpperBorder: return "sandRoadWEUpperBorder";
		case Tile::sandRoadWELowerBorder: return "sandRoadWELowerBorder";
		case Tile::sandRoadUpperLeftCorner: return "sandRoadUpperLeftCorner";
		case Tile::sandRoadUpperRightCorner: 
			return "sandRoadUpperRightCorner"; 
		case Tile::sandUpperLeft: return "sandUpperLeft"; 
		case Tile::sandUpperRight: return "sandUpperRight"; 
		case Tile::sandLowerLeft: return "sandLowerLeft";
		case Tile::sandLowerRight: return "sandLowerRight"; 
		case Tile::moos: return "moos"; 
		case Tile::moosRoadNSLeftBorder: return "moosRoadNSLeftBorder"; 
 		case Tile::moosRoadNSRightBorder: return "moosRoadNSRightBorder";
		case Tile::moosRoadWEUpperBorder: return "moosRoadWEUpperBorder";
		case Tile::moosRoadWELowerBorder: return "moosRoadWELowerBorder";
 		case Tile::moosRoadLowerLeftCorner: 
			return "moosRoadLowerLeftCornder";
		case Tile::moosRoadLowerRightCorner: 
			return "moosRoadLowerRightCorner";
		case Tile::moosRoadUpperLeftCorner:
			return "moosRoadUpperLeftCorner";
		case Tile::moosRoadUpperRightCorner:
			return "moosRoadUpperRightCorner";
 		case Tile::moosUpperRight: return "moosUpperRight";
		case Tile::moosUpperLeft: return "moosUpperLeft";
		case Tile::moosLowerRight: return "moosLowerRight";
		case Tile::moosLowerLeft: return "moosLowerLeft";
 		case Tile::mud: return "mud";
		case Tile::mudRoadNSLeftBorder: return "mudRoadNSLeftBorder";
		case Tile::mudRoadNSRightBorder: return "mudRoadNSRightBorder";
 		case Tile::mudRoadWEUpperBorder: return "mudRoadWEUpperBorder";
		case Tile::mudRoadWELowerBorder: return "mudRoadWELowerBorder";
		case Tile::mudRoadLowerLeftCorner: return "mudRoadLowerLeftCorner";
 		case Tile::mudRoadLowerRightCorner: return "mudRoadLowerRightCornder"; 		case Tile::mudRoadUpperLeftCorner: return "mudRoadUpperLeftCorner";
		case Tile::mudRoadUpperRightCorner: return "mudRoadUpperRightCorner";
 		case Tile::mudUpperRight: return "mudUpperRight";
		case Tile::mudUpperLeft: return "mudUpperLeft";
		case Tile::mudLowerRight: return "mudLowerRight"; 
		case Tile::mudLowerLeft: return "mudLowerLeft"; 
		case Tile::borderGrassDownLeft: return "borderGrassDownLeft";
		case Tile::borderGrassDownCtr: return "borderGrassDownCtr";
		case Tile::borderGrassDownRight: return "borderGrassDownRight"; 
		case Tile::borderGrassLowerRightCorner:
			return "borderGrassLowerRightCorner"; 
		case Tile::borderGrassRightCtr: return "borderGrassRightCtr";
		case Tile::borderGrassRightUp: return "borderGrassRightUp";
 		case Tile::borderGrassLowerLeftCorner: 
			return "borderGrassLowerLeftCorner";
		case Tile::borderGrassLeftCtr: return "borderGrassLeftCtr";
		case Tile::borderUpperRightCorner: return "borderUpperRightCorner";
 		case Tile::borderGrassUpperRightCorner: 
			return "borderGrassUpperRightCorner"; 
		case Tile::borderLowerLeftCorner: 
			return "borderGrassUpperRightCorner";
		case Tile::borderLeftCtr: return "borderLeftCtr";
		case Tile::borderDownLeft: return "borderDownLeft";
		case Tile::borderDownCtr: return "borderDownCtr";
		case Tile::borderDownRight: return "borderDownRight";
		case Tile::borderLowerRightCorner: 
			return "borderLowerRightCorner";
		case Tile::borderRightCtr: return "borderRightCtr";
		case Tile::borderRightUp: return "borderRightUp";
 		case Tile::deepWaterUpLeft: return "deepWaterUpLeft";
		case Tile::deepWaterUpCtr: return "deepWaterUpCtr";
		case Tile::deepWaterUpRight: return "deepWaterUpRight";
		case Tile::deepWaterCtrLeft: return "deepWaterCtrLeft";
 		case Tile::deepWaterCtrCtr: return "deepWaterCtrCtr";
		case Tile::deepWaterCtrRight: return "deepWaterCtrRight";
		case Tile::deepWaterDownLeft: return "deepWaterDownLeft";
		case Tile::deepWaterDownCtr: return "deepWaterDownCtr"; 
		case Tile::deepWaterDownRight: return "deepWaterDownRight";
		case Tile::hugeTreeUpLeft: return "hugeTreeUpLeft";
		case Tile::hugeTreeUpCtr: return "hugeTreeUpCtr";
		case Tile::hugeTreeUpRight: return "hugeTreeUpRight"; 
		case Tile::hugeTreeCtrLeft1: return "hugeTreeCtrLeft1"; 
		case Tile::hugeTreeCtrCtr1: return "hugeTreeCtrCtr1";
		case Tile::hugeTreeCtrRight1: return "hugeTreeCtrRight1"; 
		case Tile::hugeTreeCtrLeft2: return "hugeTreeCtrLeft2";
		case Tile::hugeTreeCtrCtr2: return "hugeTreeCtrCtr2";
		case Tile::hugeTreeCtrRight2: return "hugeTreeCtrRight2"; 
		case Tile::hugeTreeDownLeft: return "hugeTreeDownLeft";
		case Tile::hugeTreeDownCtr: return "hugeTreeDownCtr";
		case Tile::hugeTreeDownRight: return "hugeTreeDownRight";
		case Tile::bush: return "bush"; 
		case Tile::slenderPinTreeUp: return "slenderPinTreeUp";
		case Tile::slenderPinTreeCtr: return "slenderPinTreeCtr";
		case Tile::slenderPinTreeDown: return "slenderPinTreeDown"; 
		case Tile::pinTreeUpLeft: return "pinTreeUpLeft";
		case Tile::pinTreeUpRight: return "pinTreeUpRight";
		case Tile::pinTreeCtrLeft: return "pinTreeCtrLeft";
		case Tile::pinTreeCtrRight: return "pinTreeCtrRight";
	 	case Tile::pinTreeDownLeft: return "pinTreeDownLeft";
		case Tile::pinTreeDownRight: return "pinTreeDownRight";
		case Tile::red: return "red";
		case Tile::flora: return "flora";
		case Tile::blue: return "blue";
		case Tile::chen: return "chen";
		case Tile::mama: return "mama";
		case Tile::littleGreenGirl: return "littleGreenGirl";
		case Tile::littlePurpleGirl: return "littlePurpleGirl";
		case Tile::fatDude: return "fatDude";
		case Tile::assistant: return "assistant";
		case Tile::littleGreenBoy: return "littleGreenBoy";
		case Tile::littlePurpleBoy: return "littlePurpleBoy";
		case Tile::oldAdventurer: return "oldAdventurer";
		case Tile::nurse2: return "nurse2";
		case Tile::littleVioletGirl: return "littleVioletGirl";
		case Tile::womanRedDressBrownHairs: return "womanRedDressBrownHairs";
		case Tile::manRedSweatBlueArms: return "manRedSweatBlueArms";
		case Tile::manWhiteCollet: return "manWhiteCollet";
		case Tile::oldManBartBald: return "oldManBartBald";
		case Tile::oldLady: return "oldLady";
		case Tile::scout: return "scout";
		case Tile::parcEmployeeMale: return "parcEmployeeMale";
		case Tile::parcEmployeeFemale: return "parcEmployeeFemale";
		case Tile::mountainer: return "mountainer";
		case Tile::karateka: return "karateka";
		case Tile::rocketMale: return "rocketMale";
		case Tile::rocketFemale: return "rocketFemale";
		default : {
			throw std::runtime_error("TileManager::to_string: tile not \
			defined");
		}
	}
}


Tile TileManager::to_tile(const std::string& str) {
		if (str ==  "sand") return Tile::sand;
		else if (str == "grass1") return Tile::grass1; 
		else if (str == "grass2") return Tile::grass2; 
		else if (str == "grass3") return Tile::grass3;
		else if (str == "grass4") return Tile::grass4; 
		else if (str == "wildgrass1") return Tile::wildgrass1;
 		else if (str == "flowers1") return Tile::flowers1; 
		else if (str == "cuttree1") return Tile::cuttree1; 
		else if (str == "waterUpLeft1") return Tile::waterUpLeft1;
		else if (str == "waterUpCtr1") return Tile::waterUpCtr1;
		else if (str == "waterUpRight1") return Tile::waterUpRight1; 
		else if (str == "waterCtrLeft1") return Tile::waterCtrLeft1;
		else if (str == "waterCtrCtr1") return Tile::waterCtrCtr1; 
		else if (str == "waterCtrRight1") return Tile::waterCtrRight1; 
		else if (str == "waterDownLeft1") return Tile::waterDownLeft1;
		else if (str == "waterDownCtr1") return Tile::waterDownCtr1; 
		else if (str == "waterDownRight1") return Tile::waterDownRight1; 
		else if (str == "sandRoadNSLeftBorder") 
			return Tile::sandRoadNSLeftBorder;
		else if (str == "sandRoadNSRightBorder") 
			return Tile::sandRoadNSRightBorder;
		else if (str == "sandRoadLowerLeftCorner") {
			return Tile::sandRoadLowerLeftCorner;
		}
 		else if (str == "sandRoadLowerRightCorner") 
			return Tile::sandRoadLowerRightCorner;
		else if (str == "sandRoadWEUpperBorder") 
			return Tile::sandRoadWEUpperBorder;
		else if (str == "sandRoadWELowerBorder") 
			return Tile::sandRoadWELowerBorder;
		else if (str == "sandRoadUpperLeftCorner") 
			return Tile::sandRoadUpperLeftCorner;
		else if (str == "sandRoadUpperRightCorner") 
			return Tile::sandRoadUpperRightCorner; 
		else if (str == "sandUpperLeft")
			return Tile::sandUpperLeft; 
		else if (str == "sandUpperRight") return Tile::sandUpperRight; 
		else if (str == "sandLowerLeft") return Tile::sandLowerLeft;
		else if (str == "sandLowerRight") return Tile::sandLowerRight; 
		else if (str == "moos") return Tile::moos; 
		else if (str == "moosRoadNSLeftBorder") 
			return Tile::moosRoadNSLeftBorder; 
 		else if (str == "moosRoadNSRightBorder") 
			return Tile::moosRoadNSRightBorder;
		else if (str == "moosRoadWEUpperBorder") 
			return Tile::moosRoadWEUpperBorder;
		else if (str == "moosRoadWELowerBorder") 
			return Tile::moosRoadWELowerBorder;
 		else if (str == "moosRoadLowerLeftCorner") 
			return Tile::moosRoadLowerLeftCorner;
		else if (str == "moosRoadLowerRightCorner") 
			return Tile::moosRoadLowerRightCorner;
		else if (str == "moosRoadUpperLeftCorner")
			return Tile::moosRoadUpperLeftCorner;
		else if (str == "moosRoadUpperRightCorner")
			return Tile::moosRoadUpperRightCorner;
 		else if (str == "moosUpperRight") return Tile::moosUpperRight;
		else if (str == "moosUpperLeft") return Tile::moosUpperLeft;
		else if (str == "moosLowerRight") return Tile::moosLowerRight;
		else if (str == "moosLowerLeft") return Tile::moosLowerLeft;
 		else if (str == "mud") return Tile::mud;
		else if (str == "mudRoadNSLeftBorder") 
			return Tile::mudRoadNSLeftBorder;
		else if (str == "mudRoadNSRightBorder") 
			return Tile::mudRoadNSRightBorder;
 		else if (str == "mudRoadWEUpperBorder") 
			return Tile::mudRoadWEUpperBorder;
		else if (str == "mudRoadWELowerBorder") 
			return Tile::mudRoadWELowerBorder;
		else if (str == "mudRoadLowerLeftCorner") 
			return Tile::mudRoadLowerLeftCorner;
 		else if (str == "mudRoadLowerRightCorner")  
			return Tile::mudRoadLowerRightCorner; 		
		else if (str == "mudRoadUpperLeftCorner") 
			return Tile::mudRoadUpperLeftCorner;
		else if (str == "mudRoadUpperRightCorner") 
			return Tile::mudRoadUpperRightCorner;
 		else if (str == "mudUpperRight") return Tile::mudUpperRight;
		else if (str == "mudUpperLeft") return Tile::mudUpperLeft;
		else if (str == "mudLowerRight") return Tile::mudLowerRight; 
		else if (str == "mudLowerLeft") return Tile::mudLowerLeft; 
		else if (str == "borderGrassDownLeft") 
			return Tile::borderGrassDownLeft;
		else if (str == "borderGrassDownCtr") return Tile::borderGrassDownCtr;
		else if (str == "borderGrassDownRight") 
			return Tile::borderGrassDownRight; 
		else if (str == "borderGrassLowerRightCorner")
			return Tile::borderGrassLowerRightCorner; 
		else if (str == "borderGrassRightCtr") 
			return Tile::borderGrassRightCtr;
		else if (str == "borderGrassRightUp") return Tile::borderGrassRightUp;
 		else if (str == "borderGrassLowerLeftCorner") 
			return Tile::borderGrassLowerLeftCorner;
		else if (str == "borderGrassLeftCtr") return Tile::borderGrassLeftCtr;
		else if (str == "borderUpperRightCorner") 
			return Tile::borderUpperRightCorner;
 		else if (str == "borderGrassUpperRightCorner") 
			return Tile::borderGrassUpperRightCorner; 
		else if (str == "borderLowerLeftCorner") 
			return Tile::borderGrassUpperRightCorner;
		else if (str == "borderLeftCtr") return Tile::borderLeftCtr;
		else if (str == "borderDownLeft") return Tile::borderDownLeft;
		else if (str == "borderDownCtr") return Tile::borderDownCtr;
		else if (str == "borderDownRight") return Tile::borderDownRight;
		else if (str == "borderLowerRightCorner") 
			return Tile::borderLowerRightCorner;
		else if (str == "borderRightCtr") return Tile::borderRightCtr;
		else if (str == "borderRightUp") return Tile::borderRightUp;
 		else if (str == "deepWaterUpLeft") return Tile::deepWaterUpLeft;
		else if (str == "deepWaterUpCtr") return Tile::deepWaterUpCtr;
		else if (str == "deepWaterUpRight") return Tile::deepWaterUpRight;
		else if (str == "deepWaterCtrLeft") return Tile::deepWaterCtrLeft;
 		else if (str == "deepWaterCtrCtr") return Tile::deepWaterCtrCtr;
		else if (str == "deepWaterCtrRight") return Tile::deepWaterCtrRight;
		else if (str == "deepWaterDownLeft") return Tile::deepWaterDownLeft;
		else if (str == "deepWaterDownCtr") return Tile::deepWaterDownCtr; 
		else if (str == "deepWaterDownRight") return Tile::deepWaterDownRight;
		else if (str == "hugeTreeUpLeft") return Tile::hugeTreeUpLeft;
		else if (str == "hugeTreeUpCtr") return Tile::hugeTreeUpCtr;
		else if (str == "hugeTreeUpRight") return Tile::hugeTreeUpRight; 
		else if (str == "hugeTreeCtrLeft1") return Tile::hugeTreeCtrLeft1; 
		else if (str == "hugeTreeCtrCtr1") return Tile::hugeTreeCtrCtr1;
		else if (str == "hugeTreeCtrRight1") return Tile::hugeTreeCtrRight1; 
		else if (str == "hugeTreeCtrLeft2") return Tile::hugeTreeCtrLeft2;
		else if (str == "hugeTreeCtrCtr2") return Tile::hugeTreeCtrCtr2;
		else if (str == "hugeTreeCtrRight2") return Tile::hugeTreeCtrRight2; 
		else if (str == "hugeTreeDownLeft") return Tile::hugeTreeDownLeft;
		else if (str == "hugeTreeDownCtr") return Tile::hugeTreeDownCtr;
		else if (str == "hugeTreeDownRight") return Tile::hugeTreeDownRight;
		else if (str == "bush") return Tile::bush; 
		else if (str == "slenderPinTreeUp") return Tile::slenderPinTreeUp;
		else if (str == "slenderPinTreeCtr") return Tile::slenderPinTreeCtr;
		else if (str == "slenderPinTreeDown") 
			return Tile::slenderPinTreeDown; 
		else if (str == "pinTreeUpLeft") return Tile::pinTreeUpLeft;
		else if (str == "pinTreeUpRight") return Tile::pinTreeUpRight;
		else if (str == "pinTreeCtrLeft") return Tile::pinTreeCtrLeft;
		else if (str == "pinTreeCtrRight") return Tile::pinTreeCtrRight;
	 	else if (str == "pinTreeDownLeft") return Tile::pinTreeDownLeft;
		else if (str == "pinTreeDownRight") return Tile::pinTreeDownRight;
		else if (str == "red") return Tile::red;
		else if (str == "flora") return Tile::flora;
		else if (str == "blue") return Tile::blue;
		else if (str == "chen") return Tile::chen;
		else if (str == "mama") return Tile::mama;
		else if (str == "littleGreenGirl") return Tile::littleGreenGirl;
		else if (str == "littlePurpleGirl") return Tile::littlePurpleGirl;
		else if (str == "fatDude") return Tile::fatDude;
		else if (str == "assistant") return Tile::assistant;
		else if (str == "littleGreenBoy") return Tile::littleGreenBoy;
		else if (str == "oldAdventurer") return Tile::oldAdventurer;
		else if (str == "nurse2") return Tile::nurse2;
		else if (str == "littleVioletGirl") return Tile::littleVioletGirl;
		else if (str == "womanRedDressBrownHairs")
			return Tile::womanRedDressBrownHairs;
		else if (str == "manRedSweatBlueArms")
			return Tile::manRedSweatBlueArms;
		else if (str == "manWhiteCollet") return Tile::manWhiteCollet;
		else if (str == "oldManBartBald") return Tile::oldManBartBald;
		else if (str == "oldLady") return Tile::oldLady;
		else if (str == "scout") return Tile::scout;
		else if (str == "parcEmployeeMale") return Tile::parcEmployeeMale;
		else if (str == "parcEmployeeFemale") 
			return Tile::parcEmployeeFemale;
		else if (str == "mountainer") return Tile::mountainer;
		else if (str == "karateka") return Tile::karateka;
		else if (str == "rocketMale") return Tile::rocketMale;
		else if (str == "rocketFemale") return Tile::rocketFemale;
		else {
			throw std::runtime_error("TileManager::to_tile: " + str + " not \
			found");
		}
}


SDL_Rect TileManager::get_character_src_rect(const Tile& tile, 
const Position& pos) {
	int index = _characterRectIndexes.at(static_cast<int>(pos));
	std::cout << "TileManager::get_character_src_rect(): " <<
	index << std::endl;
	SDL_Rect frontSrc = get_src(tile);
	return {frontSrc.x + index, frontSrc.y, frontSrc.w, frontSrc.h};
}


SDL_Rect TileManager::get_brendan_src_rect(const Position& pos) {
	int xIndex = _brendanWalkXIndices.at(static_cast<int>(pos));
	int hIndex = _brendanWalkHIndices.at(static_cast<int>(pos));
	SDL_Rect frontSrc = get_src(Tile::brendan);
	return {frontSrc.x + xIndex, frontSrc.y, 
	frontSrc.w, frontSrc.h + hIndex};
}
