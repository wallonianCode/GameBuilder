#include "../Headers/DeepWater.hpp"


DeepWater::DeepWater(const SDL_FPoint& pos,
										 const DeclinedTextureOrientation& orientation) :
										 DeclinedTexture(pos) {
	SDL_FRect tile;
	switch (orientation) {
		case DeclinedTextureOrientation::North: {
			tile = {11*S+2, 4*S+1, S-3, S-3}; 
			break;
		}
		case DeclinedTextureOrientation::West: {
			tile = {10*S+1, 5*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::East: {
			tile = {12*S+2, 5*S+2, S-2, S-3};
			break;
		}
		case DeclinedTextureOrientation::South: {
			tile = {11*S+2, 6*S+2, S-3, S-2};
			break;
		}
		case DeclinedTextureOrientation::NorthWest: {
			tile = {10*S+1, 4*S+1, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthEast: {
			tile = {12*S+2, 4*S+1, S-2, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthWest: {
			tile = {10*S+1, 6*S+1, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEast: {
			tile = {12*S+2, 6*S+2, S-2, S-2};
			break;
		}
		case DeclinedTextureOrientation::Center: {
			tile = {11*S+2, 5*S+2, S-3, S-3};
			break;
		}
		default: 
			break;
	}
	this->set_pos_on_tileset({tile.x, tile.y});
	this->set_dim_on_tileset(tile.w, tile.h);
}
