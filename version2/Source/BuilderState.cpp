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
  std::cout << "BuilderState::update()" << std::endl;
	map_->update();
	std::cout << "BuilderState::update() end" << std::endl;
}


void BuilderState::draw() {
	std::cout << "BuilderState::draw() " << std::endl;
	map_->draw();
	std::cout << "BuilderState::draw() end" << std::endl;
}


BuilderState::BuilderState() {
	std::cout << "BuilderState::BuilderState" << std::endl;
	map_ = new BuilderMap();
}
