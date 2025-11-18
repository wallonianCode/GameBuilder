#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <map>

const int S = 17;
const int T = 8;
const int X = 2*T;
const int TILE_DIM = 4*S;
const int WINDOW_WIDTH = 25*TILE_DIM;
const int WINDOW_HEIGHT = 15*TILE_DIM;
const int BUILD_LEFT_BOUNDARY = WINDOW_WIDTH*1/4;
const int BUILD_SEPARATOR_RIGHT_BOUNDARY = BUILD_LEFT_BOUNDARY + 2*4*S;

const std::string SAVE_FILE_SPRITES = "Save/Sprites.txt";
const std::string SAVE_FILE_NPCS = "Save/Npcs.txt";

#endif
