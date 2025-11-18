#include "../Headers/MapUtils.hpp"


static SDL_Point MapUtils::get_tile_coord_at_mouse_pos() const {
	// get mouse position 
	int x, y;
	SDL_GetMouseState(&x, &y);
	// get tile corresponding to mouse position
	SDL_Point tileSelectedPos;
	tileSelectedPos.x = x - (x % TILE_DIM);
	tileSelectedPos.y = y - (y % TILE_DIM);

	SDL_Point tileCoord;
	tileCoord.x = tileSelectedPos.x / TILE_DIM;
	tileCoord.y = tileSelectedPos.y / TILE_DIM;
	
	return tileCoord;
}
