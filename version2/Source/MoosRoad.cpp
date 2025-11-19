#include "../Headers/MoosRoad.hpp"


MoosRoad::MoosRoad( const SDL_Point& pos,
				    const DeclinedTextureOrientation& orientation) :
					DeclinedTexture(pos)  {
	SDL_Rect tile;
	switch (orientation) {
		case DeclinedTextureOrientation::North: {
			tile = {3*S+2, 3*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::West: {
			tile = {S+2, 3*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::East: {
			tile = {2*S+2, 3*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::South: {
			tile = {4*S+2, 3*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthWest: {
			tile = {3*S+2, 4*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthEast: {
			tile = {4*S+2, 4*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthWest: {
			tile = {S+2, 4*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEast: {
			tile = {2*S+2, 4*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEastCorner: {
			tile = {S+2, 5*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthWestCorner: {
			tile = {2*S+2, 5*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthEastCorner: {
			tile = {3*S+2, 5*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthWestCorner: {
			tile = {4*S+2, 5*S+2, S-3, S-3};
			break;
		}
		default:
			break;
	}
	this->set_pos_on_tileset(tile.x, tile.y);
	this->set_dim_on_tileset(tile.w, tile.h);
					
}