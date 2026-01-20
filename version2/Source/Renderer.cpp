#include "../Headers/Renderer.hpp"

Renderer* Renderer::instance_ = nullptr;

Renderer* Renderer::get_instance() {
	if (! instance_) instance_ = new Renderer();
	return instance_;
}


SDL_Renderer* Renderer::get_sdl_renderer() {
	return renderer_;
}


void Renderer::print() {
	SDL_RenderPresent(renderer_);
}


/*
void Renderer::reset(Background* background) {
	//TODO
}
*/

Renderer::Renderer() {
	Window* window = Window::get_instance();
	renderer_ = SDL_CreateRenderer(window->get_sdl_window(), NULL);
	if (! renderer_) {
		std::cout << SDL_GetError() << std::endl;
		throw std::runtime_error(std::string(__FUNCTION__) + 
		std::string(": failed renderer init"));
	}
	SDL_SetRenderLogicalPresentation(renderer_, window->get_width(),
	window->get_height(), SDL_LOGICAL_PRESENTATION_LETTERBOX);
}
