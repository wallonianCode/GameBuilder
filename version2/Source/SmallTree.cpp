#include "../Headers/SmallTree.hpp"


SmallTree::SmallTree(const SDL_Point& posOnScreen) : 
SimpleTexture(posOnScreen) {
	this->set_pos_on_tileset({8*S+2, 2});
	this->set_dim_on_tileset(S-3, S-3);
}
