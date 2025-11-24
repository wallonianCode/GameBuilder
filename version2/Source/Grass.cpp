#include "../Headers/Grass.hpp"



Grass::Grass(const SDL_Point& pos, const GrassType& grassType) : SimpleTexture(pos) {
	SDL_Rect tile;

	switch (orientation) {
		case GrassType::GreenWhite: {
			tile = {6*S+2, 2, S-3, S-3};
			break;
		}
		case GrassType::GreenWhiteGreen: {
			tile = {6*S+2, S+2, S-3, S-3};
			break;
		}
		case GrassType::Green: {
			tile = {7*S+2, S+2, S-3, S-3};
			break;
		}
		case GrassType::White: {
			tile = {6*S+2, 2*S+2, S-3, S-3};
			break;
		}
		default:
			break;
	}
	this->set_pos_on_tileset(tile.x, tile.y);
	this->set_dim_on_tileset(tile.w, tile.h);
}