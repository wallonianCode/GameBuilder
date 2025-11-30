#include "../Headers/GameMenuState.hpp"


GameState* GameMenuState::process_events(bool& running) {
	SDL_Event event;
	GameState* nextState = nullptr;
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
	  nextState = menu_->handle_event(event);
	}
	return nextState;
}


void GameMenuState::update() {
	menu_->update();
}


void GameMenuState::draw() {
	menu_->draw();
}


GameMenuState::GameMenuState() {
	menu_ = std::make_shared<GameMenu>();
}
