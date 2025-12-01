#include "../Headers/Moos.hpp"


Moos::Moos(const SDL_FPoint& posOnScreen) :
SimpleTexture(posOnScreen) {
	this->set_pos_on_tileset({2, 3*S+2});
	this->set_dim_on_tileset(S-3, S-3);
}
