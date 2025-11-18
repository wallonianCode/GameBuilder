#include "../Headers/ShallowWater.hpp"


void ShallowWater::save(std::ostream& os) {
	os << "ShallowWater" << " ";
	os << side_.to_str() << " ";
	Texture::save(os);
}


ShallowWater::ShallowWater(const SDL_Point& posOnScreen) :
Water(posOnScreen) {
	init_src();
}


ShallowWater::ShallowWater(const SDL_Point& posOnScreen, 
const LeafGreenTexture::Side& side) : 
Water(posOnScreen, side){
	init_src(side);
}


ShallowWater::ShallowWater(const SDL_Point& posOnScreen,
const std::string& subType) : ShallowWater(posOnScreen, 
LeafGreenTexture::Side::to_side(subType)) {}
	

void ShallowWater::init_src() {
	this->set_pos_on_tileset({11*S+2, S+2});
	this->set_dim_on_tileset(S-3, S-3);
}
	

void ShallowWater::init_src(const LeafGreenTexture::Side& side) {
	SDL_Rect srcRect = rectAr[side.to_int()];
	this->set_pos_on_tileset({srcRect.x, srcRect.y});
	this->set_dim_on_tileset(srcRect.w, srcRect.h);
}
