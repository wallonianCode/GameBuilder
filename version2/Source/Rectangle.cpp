#include "../Headers/Rectangle.hpp"


void Rectangle::draw() {
	Renderer* renderer = Renderer::get_instance();
	SDL_SetRenderDrawColor(renderer->get_sdl_renderer(), color_.r, 
	color_.g, color_.b, color_.a);
	SDL_RenderFillRect(renderer->get_sdl_renderer(), areaOnScreen_);
}


int Rectangle::get_height() const {
	return areaOnScreen_->h;
}

int Rectangle::get_width() const {
	return areaOnScreen_->w;
}

int Rectangle::get_x() const {
	return areaOnScreen_->x;
}

int Rectangle::get_y() const {
	return areaOnScreen_->y;
}


void Rectangle::set_width(const int width) {
	areaOnScreen_->w = width;
}

void Rectangle::set_height(const int height) {
	areaOnScreen_->h = height;
}


SDL_Point get_position() const {
	return { areaOnScreen_->x, areaOnScreen_->y };
}

SDL_Point get_coord() const {
	SDL_Point coord;
	coord.x = areaOnScreen_.x - (areaOnScreen_.x % TILE_DIM);
	coord.y = areaOnScreen_.y - (areaOnScreen_.y % TILE_DIM);
	return coord;
}


void Rectangle::set_pos_on_screen(const SDL_Point& newPos) {
	areaOnScreen_->x = newPos.x;
	areaOnScreen_->y = newPos.y;
}


void Rectangle::set_color(const SDL_Color& newColor) {
	color_ = newColor;
}

Rectangle::Rectangle() {
	color_ = Color::black;
	areaOnScreen_ = new SDL_Rect({100, 100, 100, 100});
}


Rectangle::Rectangle(const SDL_Rect& areaOnScreen, 
const SDL_Color& color) : color_(color) {
	areaOnScreen_ = new SDL_Rect(areaOnScreen);
}


Rectangle::Rectangle(const SDL_Point& posOnScreen, const int& width,
const int& height, const SDL_Color& color) : color_(color) {
	areaOnScreen_ = 
	new SDL_Rect({posOnScreen.x, posOnScreen.y, width, height});
}
