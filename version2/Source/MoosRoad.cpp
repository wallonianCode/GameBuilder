#include "../Headers/MoosRoad.hpp"


MoosRoad::MoosRoad(const SDL_Point& posOnScreen) : 
Road(posOnScreen) {
	init_src();
}


MoosRoad::MoosRoad(const SDL_Point& posOnScreen, 
const LeafGreenTexture::Side& side) : 
Road(posOnScreen), side_(side) {
	init_src(side);
}


MoosRoad::MoosRoad(const SDL_Point& posOnScreen, 
const std::string& side) :
MoosRoad(posOnScreen, LeafGreenTexture::Side::to_side(side)) {}


//default value
void MoosRoad::init_src() {
	set_pos_on_tileset({2, 3*S+2});
	set_dim_on_tileset(S-3, S-3);
}


void MoosRoad::init_src(const LeafGreenTexture::Side& side) {
	SDL_Rect srcRect = arSrcRect[side.to_int()];
	set_pos_on_tileset({srcRect.x, srcRect.y});
	set_dim_on_tileset(srcRect.w, srcRect.h);
}
