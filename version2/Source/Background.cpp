#include "../Headers/Background.hpp"


void Background::draw() {	
	Renderer* renderer = Renderer::get_instance();
	SDL_SetRenderDrawColor(renderer->get_sdl_renderer(), color_.r, 
	color_.g, color_.b, color_.a);
  SDL_RenderClear(renderer->get_sdl_renderer());
}


Background::Background(const SDL_Color& color) : color_(color) {}
