#include "../Headers/GameManager.hpp"

GameManager* GameManager::instance_ = nullptr;


GameManager* GameManager::get_instance() {
	if (! instance_) instance_ = new GameManager();
	return instance_;
}

void GameManager::run() {
	bool running = true;
	GameStateMachine* stateMachine = GameStateMachine::get_instance();
	while (running) {
		running = !(stateMachine->handle_frame());
	}
}


GameManager::GameManager() {}
