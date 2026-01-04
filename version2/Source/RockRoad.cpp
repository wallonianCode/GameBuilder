#include "../Headers/RockRoad.hpp"


RockRoad::RockRoad(const SDL_FPoint& pos, 
				   const DeclinedTextureOrientation& orientation) :
DeclinedTexture(pos) {
	SDL_FRect tile; 
	switch (orientation) {
		case DeclinedTextureOrientation::North: {
			tile = {3*S+2, 6*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::West: {
			tile = {S+2, 6*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::East: {
			tile = {2*S+2, 6*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::South: {
			tile = {4*S+2, 6*S+2, S-3, S-3};
			break;
		}
			case DeclinedTextureOrientation::NorthWest: {
			tile = {3*S+2, 7*S+2, S-3, S-3};
			break;
		}
			case DeclinedTextureOrientation::NorthEast: {
			tile = {4*S+2, 7*S+2, S-3, S-3};
			break;
		}
			case DeclinedTextureOrientation::SouthWest: {
			tile = {S+2, 7*S+2, S-3, S-3};
			break;
		}
			case DeclinedTextureOrientation::SouthEast: {
			tile = {2*S+2, 7*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEastCorner: {
			tile = {S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthWestCorner: {
			tile = {2*S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthEastCorner: {
			tile = {3*S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::NorthWestCorner: {
			tile = {4*S+2, 8*S+2, S-3, S-3};
			break;
		}
		default:
			break;
	}
	this->set_pos_on_tileset({tile.x, tile.y});
	this->set_dim_on_tileset(tile.w, tile.h);
	std::cout << "RockRoad::RockRoad: " <<
	this->get_upper_left_corner().x << ":" <<
	this->get_upper_left_corner().y << std::endl;
}
