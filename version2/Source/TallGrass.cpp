#include "../Headers/TallGrass.hpp"



TallGrass::TallGrass(const SDL_Point& posOnScreen) : 
SimpleTexture(posOnScreen) {
	this->set_pos_on_tileset({7*S+2, 2});
	this->set_dim_on_tileset(S-3, S-3);
}
