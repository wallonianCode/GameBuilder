#include "../Headers/BuilderState.hpp"


GameState* BuilderState::process_events(bool& running) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode) {
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
	map_->draw();
}


BuilderState::BuilderState() {
	map_ = new BuilderMap();
}
