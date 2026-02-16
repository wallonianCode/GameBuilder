#include "../Headers/SimpleTexture.hpp"


SimpleTexture::SimpleTexture() : Texture(leafGreenTextureFileName) {
	// default to the middle of the screen
	this->set_upper_left_corner({WINDOW_WIDTH/2, WINDOW_HEIGHT/2});
	this->set_dimensions_on_screen(TILE_DIM, TILE_DIM);
}


//TODO build a simple example of this first without, and then with 
// the CRTP
SimpleTexture::SimpleTexture(const SDL_FPoint& pos) : 
Texture(leafGreenTextureFileName) {
	this->set_upper_left_corner(pos);
	this->set_dimensions_on_screen(TILE_DIM, TILE_DIM);
}


SimpleTexture::SimpleTexture(const std::string& tileset, 
const SDL_FPoint& pos) : 
Texture(tileset) {
	this->set_upper_left_corner(pos);
	this->set_dimensions_on_screen(TILE_DIM, TILE_DIM);
}


SimpleTexture::SimpleTexture(const SimpleTexture& other) :
Texture(other) {
	src_ = other.src_;
	dest_ = other.dest_;

}


void SimpleTexture::draw() {
	Renderer* renderer = Renderer::get_instance();
	SDL_Texture* texture = 
	TextureLoader::load_texture
	(renderer->get_sdl_renderer(), this->get_tileset());
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


bool SimpleTexture::is_coord_in_texture(const SDL_FPoint& coord) const {
	return (get_upper_left_corner().x == coord.x && get_upper_left_corner().y == coord.y);
}


float SimpleTexture::get_standard_width() {
	return TILE_DIM;
}


float SimpleTexture::get_standard_height() {
	return TILE_DIM;
}


TextureTableEntry SimpleTexture::get_entry() const {
	TextureTableEntry entry;
	entry.tileset = this.get_tileset();
	entry.widthOnTileset = this.src_.w;
	entry.heightOnTileset = this.src_.h;
	entry.xOnTileset = this.src_.x;
	entry.yOnTileset = this.src_.y;
	entry.widthOnMap = this.dest_.w;
	entry.heightOnMap = this.dest_.h;
	entry.xOnMap = this.dest_.x;
	entry.yOnMap = this.dest_.y;	
	return entry;
}
