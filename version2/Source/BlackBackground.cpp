#include "../Headers/BlackBackground.hpp"


BlackBackground::Blackbackground(const float width, const float height) :
width_(width), height_(height) {}


void BlackBackground::draw() {
  Renderer* renderer = Renderer::get_instance();
	SDL_SetRenderDrawColor(renderer->get_sdl_renderer(), 0, 0, 0, 255);
	SDL_RenderClear(renderer->get_sdl_renderer());
}
