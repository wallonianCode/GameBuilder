#include "../Headers/Sand.hpp"


Sand::Sand(const SDL_FPoint& posOnScreen) : 
SimpleTexture(posOnScreen) {
	this->set_pos_on_tileset({2, 2});
	this->set_dim_on_tileset(S-2, S-2);
}
