#include "../Headers/Rock.hpp"


Rock::Rock(const SDL_FPoint& posOnScreen) : 
SimpleTexture(posOnScreen) {
	this->set_pos_on_tileset({2, 6*S+2});
	this->set_dim_on_tileset(S-3, S-3);
}
