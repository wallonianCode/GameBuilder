#include "../Headers/Frame.hpp"

void Frame::draw() {
	draw_outline();
}


void Frame::draw_outline() {
	SDL_SetRenderDrawColor(Renderer::get_instance()->get_sdl_renderer(), 
	color_.r, color_.g, color_.b, color_.a);
	SDL_RenderRect(Renderer::get_instance()->get_sdl_renderer(), 
	areaOnScreen_);
}


void Frame::follow_mouse_motion() {
	if (! isImmobilized_) {
		float x, y, xTile, yTile;
		SDL_GetMouseState(&x, &y);
		xTile = x - ((int)x % TILE_DIM);
		yTile = y - ((int)y % TILE_DIM);
		this->set_upper_left_corner({xTile, yTile});
	}
}


void Frame::immobilize() {
	this->isImmobilized_ = true;
}


void Frame::free() {
	this->isImmobilized_ = false;
}


Frame::Frame(): Rectangle(Color::red) {
  	
}


Frame::Frame(const SDL_FRect& areaOnScreen, const SDL_Color& color) :
Rectangle(areaOnScreen, color) {}


Frame::Frame(const SDL_FPoint& pos, const int& width, 
const int& height, const SDL_Color& color) : 
Rectangle( pos, width, height, color) {}
