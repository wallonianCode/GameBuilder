#include "../Headers/Frame.hpp"

void Frame::draw() {
	draw_outline();
}


void Frame::draw_outline() {
	SDL_SetRenderDrawColor(Renderer::get_instance()->get_sdl_renderer(), 
	color_.r, color_.g, color_.b, color_.a);
	SDL_RenderDrawRect(Renderer::get_instance()->get_sdl_renderer(), 
	areaOnScreen_);
}


void Frame::follow_mouse_motion() {
	if (! isImmobilized_) {
		int x, y, xTile, yTile;
		SDL_GetMouseState(&x, &y);
		xTile = x - (x % TILE_DIM);
		yTile = y - (y % TILE_DIM);
		this->set_pos_on_screen(xTile, yTile);
	}
}


void Frame::immobilize() {
	this->isImmobilized_ = true;
}


void Frame::free() {
	this->isImmobilized_ = false;
}


Frame::Frame(): Rectangle({0, 0, TILE_DIM, TILE_DIM}, Color::red) {
  	
}


Frame::Frame(const SDL_Rect& areaOnScreen, const SDL_Color& color) :
Rectangle(areaOnScreen, color) {}


Frame::Frame(const SDL_Point& posOnScreen, const int& width, 
const int& height, const SDL_Color& color) : 
Rectangle( posOnScreen, width, height, color) {}
