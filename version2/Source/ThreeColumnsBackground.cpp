#include "../Headers/ThreeColumnsBackground.hpp"

//TODO try out with three rectangles in order to get the right color
void ThreeColumnsBackground::draw() {
	Window* window;
	Renderer* renderer;
	SDL_FRect leftSDLRect, centralSDLRect, rightSDLRect;
	Rectangle leftRect, centralRect, rightRect;
	
	window = Window::get_instance();
	renderer = Renderer::get_instance();

	leftSDLRect = {0.0f, 0.0f, 
	window->get_width()/3.0f, (float)window->get_height()};
 	centralSDLRect = {window->get_width()/3.0f, 0.0f, 
										window->get_width()/3.0f, 
										(float)window->get_height()};
	rightSDLRect = {2*window->get_width()/3.0f, 0.0f,
									window->get_width()/3.0f, (float)window->get_height()};

	leftRect = Rectangle(leftSDLRect, backgroundColor_);
  centralRect =  Rectangle(centralSDLRect, foregroundColor_);
	rightRect = Rectangle(rightSDLRect, backgroundColor_);
	
	SDL_SetRenderDrawColor(renderer->get_sdl_renderer(), 0, 0, 0, 255);
	SDL_RenderClear(renderer->get_sdl_renderer());
	
	leftRect.draw();
	centralRect.draw();
	rightRect.draw();
}


ThreeColumnsBackground::ThreeColumnsBackground(const SDL_Color& backColor,
const SDL_Color& foreColor) : backgroundColor_(backColor), foregroundColor_(foreColor) {}
