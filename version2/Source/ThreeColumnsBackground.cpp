#include "../Headers/ThreeColumnsBackground.hpp"

//TODO try out without pointers, or with pointers as members?
void ThreeColumnsBackground::draw() {
	Window* window;
	Renderer* renderer;
	SDL_Rect foregroundSDLRect; 
	
	window = Window::get_instance();
	renderer = Renderer::get_instance();

 	foregroundSDLRect = {window->get_width()/3, 0, 
					  window->get_width()/3, window->get_height()};
  foregroundRect =  Rectangle(foregroundSDLRect, foregroundColor_);
	
	SDL_SetRenderDrawColor(renderer->get_sdl_renderer(), 
	backgroundColor_.r, backgroundColor_.g, backgroundColor_.b,
	backgroundColor_.a);
	SDL_RenderClear(renderer->get_sdl_renderer());
 	foregroundRect.draw();
}


ThreeColumnsBackground::ThreeColumnsBackground(const SDL_Color& backColor,
const SDL_Color& foreColor) : backgroundColor_(backColor), foregroundColor_(foreColor) {}
