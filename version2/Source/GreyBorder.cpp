#include "../Headers/GreyBorder.hpp"


GreyBorder::GreyBorder(const SDL_FPoint& pos,
					   const DeclinedTextureOrientation& orientation) :
					   DeclinedTexture(pos) {
	SDL_FRect tile;
	switch (orientation) {
		case DeclinedTextureOrientation::SouthWest: {
			tile = {6*S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::South: {
			tile = {7*S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEast: {
			tile = {8*S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEastCorner: {
			tile = {6*S+2, 9*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::East: {
			tile = {7*S+2, 9*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthEast: {
			tile = {8*S+2, 9*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthWestCorner: {
			tile = {7*S+2, 7*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::West: {
			tile = {8*S+2, 7*S+2, S-3, S-3};
			break;		
		}
		case DeclinedTextureOrientation::NorthEastCorner: {
			tile = {8*S+2, 6*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::Center: {
			tile = {6*S+2, 2, S-3, S-3};
			break;
		}
		default: 
			break;
	}
	this->set_pos_on_tileset({tile.x, tile.y});
	this->set_dim_on_tileset(tile.w, tile.h);
}
