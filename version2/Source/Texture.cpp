#include "../Headers/Texture.hpp"


void Texture::draw() {}


void Texture::draw_shadow() {}


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


float Texture::get_width() const {
	return TILE_DIM;
}


float Texture::get_height() const {
	return TILE_DIM;
}


Texture::Texture(const std::string& tileset) : tileset_(tileset) {}

Texture::Texture() : tileset_(leafGreenTextureFileName) {}