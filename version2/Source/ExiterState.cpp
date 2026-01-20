#include "../Headers/ExiterState.hpp"


GameState* ExiterState::process_event(bool& running, SDL_Event* event) {
	return nullptr;
}


void ExiterState::update() {}


void ExiterState::draw() {
	background_->draw();
}


ExiterState::ExiterState() {
	background_ = std::make_shared<BlackBackground>();
}
