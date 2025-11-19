#include "../Headers/GreyBorder.hpp"

/**
GreyBorder::GreyBorder(const SDL_Point& posOnScreen) : 
Border(posOnScreen) {
	init_src();
}


GreyBorder::GreyBorder(const SDL_Point& posOnScreen, 
const Border::Side& side) : 
Border(posOnScreen), side_(side) {
	init_src(side);
}


GreyBorder::GreyBorder(const SDL_Point& posOnScreen, 
const std::string& side) : 
GreyBorder(posOnScreen, Border::Side::to_side(side)) {}


void GreyBorder::save(std::ostream& os) const {
	os << "GreyBorder" << " ";
	os << side_.to_str() << " ";
	Texture::save(os);
}


void GreyBorder::init_src() {
	set_pos_on_tileset({7*S+2, 8*S+2});
	set_dim_on_tileset(S-3, S-3);
}


void GreyBorder::init_src(const Border::Side& side) {
	SDL_Rect rect = arSrcRect[side.to_int()];
	set_pos_on_tileset({rect.x, rect.y});
	set_dim_on_tileset(rect.w, rect.h);
}
*/
//TODO complete this blueprint
GreyBorder::GreyBorder(const SDL_Point& pos,
											 const DeclinedTextureOrientation& orientation) :
											 DeclinedTexture(pos) {
	SDL_Rect tile;
	switch (orientation) {
		case DeclinedTextureOrientation::SouthWest {
			tile = {6*S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::South {
			tile = {7*S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEast {
			tile = {8*S+2, 8*S+2, S-3, S-3};
			break;
		}
		case DeclinedTextureOrientation::SouthEastCorner {
			break;
		}
		case DeclinedTextureOrientation::East {
			break;
		}
		case DeclinedTextureOrientation::NorthEast {
			break;
		}
		case DeclinedTextureOrientation::SouthWestCorner {
			break;
		}
		case DeclinedTextureOrientation::West {
			break;
		}
		case DeclinedTextureOrientation::NorthEastCorner {
			break;
		}
		case DeclinedTextureOrientation::Center {
			break;
		}
		default: 
			break;
	}
	this->set_pos_on_tileset(tile.x, tile.y);
	this->set_dim_on_tileset(tile.x, tile.y, tile.w, tile.h);
}
