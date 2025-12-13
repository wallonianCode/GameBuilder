#include "../Headers/BuilderState.hpp"


GameState* BuilderState::process_events(bool& running) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_EVENT_QUIT:
				running = false;
				break;
			case SDL_EVENT_KEY_DOWN:
				switch (event.key.scancode) {
					case SDL_SCANCODE_ESCAPE:
						running = false;
						break;
					default:
						break;
				}
			default:
				break;
		}
		map_->handle_event(event);
	}
	return nullptr;
}


void BuilderState::update() {
	map_->update();
}


void BuilderState::draw() {
	Renderer* renderer;
	renderer = Renderer::get_instance();
	map_->draw();
	SDL_RenderPresent(renderer->get_sdl_renderer());
	std::cout << "BuilderState::draw()" << std::endl;
}


BuilderState::BuilderState() {
	map_ = new BuilderMap();
}
