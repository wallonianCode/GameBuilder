#include "../Headers/Rectangle.hpp"


void Rectangle::draw() {
	Renderer* renderer = Renderer::get_instance();
	SDL_SetRenderDrawColor(renderer->get_sdl_renderer(), color_.r, 
	color_.g, color_.b, color_.a);
	SDL_RenderFillRect(renderer->get_sdl_renderer(), areaOnScreen_);
}


float Rectangle::get_height() const {
	return areaOnScreen_->h;
}

float Rectangle::get_width() const {
	return areaOnScreen_->w;
}

float Rectangle::get_x() const {
	return areaOnScreen_->x;
}

float Rectangle::get_y() const {
	return areaOnScreen_->y;
}


void Rectangle::set_width(const float width) {
	areaOnScreen_->w = width;
}

void Rectangle::set_height(const float height) {
	areaOnScreen_->h = height;
}


SDL_FPoint Rectangle::get_position() const {
	return { areaOnScreen_->x, areaOnScreen_->y };
}

SDL_FPoint Rectangle::get_coord() const {
	SDL_FPoint coord;
	coord.x = areaOnScreen_->x - ((int)areaOnScreen_->x % TILE_DIM);
	coord.y = areaOnScreen_->y - ((int)areaOnScreen_->y % TILE_DIM);
	return coord;
}


void Rectangle::set_upper_left_corner(const SDL_FPoint& newPos) {
	areaOnScreen_->x = newPos.x;
	areaOnScreen_->y = newPos.y;
}


void Rectangle::set_color(const SDL_Color& newColor) {
	color_ = newColor;
}

Rectangle::Rectangle() {
	color_ = Color::black;
	areaOnScreen_ = new SDL_FRect({0, 0, TILE_DIM, TILE_DIM});
}


Rectangle::Rectangle(const SDL_Color& color) {
	color_ = color;
	areaOnScreen_ = new SDL_FRect({0, 0, TILE_DIM, TILE_DIM});
}


Rectangle::Rectangle(const SDL_FRect& areaOnScreen, 
					 const SDL_Color& color) : color_(color) {
	areaOnScreen_ = new SDL_FRect(areaOnScreen);
}


Rectangle::Rectangle(const SDL_FPoint& posOnScreen, const float& width,
const float& height, const SDL_Color& color) : color_(color) {
	areaOnScreen_ = 
	new SDL_FRect({posOnScreen.x, posOnScreen.y, width, height});
}
