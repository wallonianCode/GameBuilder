#include "../Headers/Texture.hpp"

/*
//--------------------- TEXTUREPOSCOMPARATOR -----------------------
bool TexturePosComparator::operator()(const Texture& texture) {
	SDL_Point pos = texture.get_upper_left_corner();
	return ((pos.x == posOnScreen_.x) && (pos.y == posOnScreen_.y));
}

bool TexturePosComparator::operator()(Texture* texture) {
	SDL_Point pos = texture->get_upper_left_corner();
	return ((pos.x == posOnScreen_.x) && (pos.y == posOnScreen_.y));
}

TexturePosComparator::TexturePosComparator(const SDL_Point& pos) : 
posOnScreen_(pos) {}


//---------------------- TEXTURE ----------------------------------
*/

void Texture::draw() {}


void Texture::update() {}


SDL_FPoint Texture::get_upper_left_corner() const {
	return {0, 0};
}

void Texture::set_upper_left_corner(const SDL_FPoint& upperLeftCorner) {}
 

void Texture::set_pos_on_tileset(const SDL_FPoint& pos) {}


void Texture::set_dim_on_tileset(const int width, const int height) {}


Texture* Texture::clone() const {
	return nullptr;
}