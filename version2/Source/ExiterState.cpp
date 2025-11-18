#include "../Headers/ExiterState.hpp"


GameState* ExiterState::process_events(bool& running) {
	return nullptr;
}


void ExiterState::update() {}


void ExiterState::draw() {
	background_->draw();
}


ExiterState::ExiterState() {
	background_ = std::make_shared<Background>(Color::black);
}
