#include "../Headers/SimpleTexture.hpp"


SimpleTexture::SimpleTexture() : tileset_(leafGreenSimpleTextureFileName) {
	// middle of the screen
	this->init_dest({WINDOW_WIDTH/2, WINDOW_HEIGHT/2});	
}


SimpleTexture::SimpleTexture(const std::string& tileset, 
const SDL_Point& posOnScreen) : tileset_(tileset) {
	this->init_dest(posOnScreen);
}


void SimpleTexture::draw() {
	Renderer* renderer = Renderer::get_instance();
	SDL_Texture* texture = 
	TextureLoader::load_texture
	(renderer->get_sdl_renderer(), tileset_);
	SDL_RenderCopy(renderer->get_sdl_renderer(), texture, &src_, &dest_);
}


void SimpleTexture::set_pos_on_screen(const SDL_Point& posOnScreen) {
	dest_.x = posOnScreen.x;
	dest_.y = posOnScreen.y;
}


void SimpleTexture::update() {}


SDL_Point SimpleTexture::get_pos_on_screen() const {
	return { dest_.x, dest_.y };
}


void SimpleTexture::set_x_pos_on_tileset(const int x) {
	src_.x = x;
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


void SimpleTexture::save_dest(std::ostream& os) const {
	os << dest_.x << "," << dest_.y << "," << 
	dest_.w << "," << dest_.h << " ";
}


std::ostream& operator<<(std::ostream& os, const SimpleTexture& texture) {
	texture.save(os);
	return os;
}


/**
SDL_Point SimpleTexture::get_next_pos() const {
	int x, y;
	SDL_GetMouseState(&x, &y);
	return {x, y};
}
*/


void SimpleTexture::save(std::ostream& os) const {
	os << to_str() << " ";
	this->save_dest(os);
}


void SimpleTexture::set_pos_on_tileset(const SDL_Point& pos) {
	src_.x = pos.x;
	src_.y = pos.y;	
}


void SimpleTexture::init_dest(const SDL_Point& posOnScreen) {
	this->set_pos_on_screen(posOnScreen);
	this->set_dimensions_on_screen(STD_WIDTH, STD_HEIGHT);
}


std::string SimpleTexture::to_str() const {
	return "Grass";
}


void SimpleTexture::init_src() {
	src_ = {6*S+2, 2, S-3, S-3};
}
