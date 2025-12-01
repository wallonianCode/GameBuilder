#include "../Headers/ThreeColumnsBackground.hpp"


void ThreeColumnsBackground::draw() {
	Window* window = Window::get_instance();
	
	SDL_Rect foregroundRect = {window->get_width()/3, 0, 
	window->get_width()/3, window->get_height()};
	Rectangle rect(foregroundRect, foregroundColor_);
	
	rect.draw();
}


ThreeColumnsBackground::ThreeColumnsBackground(const SDL_Color& backColor,
const SDL_Color& foreColor) : 
foregroundColor_(foreColor) {}
