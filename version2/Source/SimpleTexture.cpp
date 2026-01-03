#include "../Headers/SimpleTexture.hpp"


SimpleTexture::SimpleTexture() : tileset_(leafGreenTextureFileName) {
	// default to the middle of the screen
	this->set_upper_left_corner({WINDOW_WIDTH/2, WINDOW_HEIGHT/2});
	this->set_dimensions_on_screen(TILE_DIM, TILE_DIM);
}


SimpleTexture::SimpleTexture(const SDL_FPoint& pos) : tileset_(leafGreenTextureFileName) {
	this->set_upper_left_corner(pos);
	this->set_dimensions_on_screen(TILE_DIM, TILE_DIM);
}



SimpleTexture::SimpleTexture(const std::string& tileset, const SDL_FPoint& pos) : 
tileset_(tileset) {
	this->set_upper_left_corner(pos);
	this->set_dimensions_on_screen(TILE_DIM, TILE_DIM);
}


void SimpleTexture::draw() {
	Renderer* renderer = Renderer::get_instance();
	SDL_Texture* texture = 
	TextureLoader::load_texture
	(renderer->get_sdl_renderer(), tileset_);
	std::cout << "SimpleTexture::draw() " << (texture == nullptr) << 
	" " << src_.x << ":" << src_.y << ", " << src_.w << ":" << 
	src_.h <<	", " << dest_.x << ":" << dest_.y << ", " << dest_.w <<
	":" << dest_.h << std::endl;
	SDL_RenderTexture(renderer->get_sdl_renderer(), texture, &src_, &dest_);
}


void SimpleTexture::set_upper_left_corner(const SDL_FPoint& posOnScreen) {
	dest_.x = posOnScreen.x;
	dest_.y = posOnScreen.y;
}


void SimpleTexture::update() {}


SDL_FPoint SimpleTexture::get_upper_left_corner() const {
	return { dest_.x, dest_.y };
}



void SimpleTexture::set_dim_on_tileset(const int width, const int height) {
	src_.w = width;
	src_.h = height;
}


void SimpleTexture::set_dimensions_on_screen(const int& width, 
const int& height) {
	dest_.w = width;
	dest_.h = height;
}


void SimpleTexture::set_pos_on_tileset(const SDL_FPoint& pos) {
	src_.x = pos.x;
	src_.y = pos.y;	
}


float SimpleTexture::get_width() const {
	return dest_.w;
}

float SimpleTexture::get_height() const {
	return dest_.h;
}


float SimpleTexture::get_standard_width() {
	return TILE_DIM;
}


float SimpleTexture::get_standard_height() {
	return TILE_DIM;
}
