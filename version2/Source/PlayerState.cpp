#include "../Headers/PlayerState.hpp"


GameState* PlayerState::process_event(bool& running, SDL_Event* event) {
	switch (event->type) {
		case SDL_EVENT_QUIT:
			running = false;
			break;
		case SDL_EVENT_KEY_DOWN:
			switch (event->key.scancode) {
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
	return nullptr;
}


void PlayerState::update() {
	map_->update();
}


void PlayerState::draw() {
	map_->draw();
}


PlayerState::PlayerState() {
	map_ = std::make_shared<PlayerMap>();
}
