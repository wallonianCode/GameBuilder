#include "../Headers/GreenBorder.hpp"

GreenBorder::GreenBorder(const SDL_Point& pos,
												 const DeclinedTextureOrientation& orientation) :
												 DeclinedTexture(pos) {
	SDL_Rect tile;
	switch (orientation) {
		case DeclinedTextureOrientation::SouthWest {
			tile = {6*S+2, 4*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::South {
			tile = {7*S+2, 4*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEast {
			tile = {8*S+2, 6*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEastCorner {
			tile = {6*S+2, 5*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::East {
			tile = {7*S+2, 5*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthEast {
			tile = {8*S+2, 5*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthWestCorner {
			tile = {6*S+2, 6*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::West {
			tile = {7*S+2, 6*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthEastCorner {
			tile = {6*S+2, 7*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::Center {
			tile = {6*S+2, 2, S-3, S-3};
		}
		default: 
			break;
	}
	this->set_pos_on_tileset(tile.x, tile.y);
	this->set_dim_on_tileset(tile.x, tile.y, tile.w, tile.h);
}
