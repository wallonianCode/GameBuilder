#include "../Headers/SandRoad.hpp"


//------------------------ CONSTRUCTORS ------------------------------
SandRoad::SandRoad(const SDL_Point& posOnScreen) :
Road(posOnScreen) {
	init_src();
}


SandRoad::SandRoad(const SDL_Point& posOnScreen, 
const LeafGreenTexture::Side& side) : 
Road(posOnScreen), side_(side) {
	init_src(side);
}


SandRoad::SandRoad(const SDL_Point& posOnScreen, 
const std::string& subType) :
Road(posOnScreen), side_(Road::Side::to_side(subType)) {}
//--------------------------------------------------------------------

void SandRoad::init_src() {
	set_pos_on_tileset({2, 2});
	set_dim_on_tileset(S-2, S-2);
}


void SandRoad::init_src(const LeafGreenTexture::Side& side) {
	SDL_Rect rect = arSrcRect[side.to_int()];	
	set_pos_on_tileset({rect.x, rect.y});
	set_dim_on_tileset(rect.w, rect.h);
}
