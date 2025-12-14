#include "../Headers/GameManager.hpp"

GameManager* GameManager::instance_ = nullptr;


GameManager* GameManager::get_instance() {
	if (! instance_) instance_ = new GameManager();
	return instance_;
}

void GameManager::run() {
	bool running; 
	uint64_t start, end;
	float elapsedS, elapsedMS;
	GameStateMachine* stateMachine; 
	
	running = true;
	stateMachine = GameStateMachine::get_instance();

	while (running) {
		start = SDL_GetPerformanceCounter();
		running = !(stateMachine->handle_frame());
		end = SDL_GetPerformanceCounter();
	  elapsedS = (end - start)/(float)SDL_GetPerformanceFrequency();
		elapsedMS = elapsedS*1000.0f;
		SDL_Delay(std::floor(16.666f - elapsedMS));
	}
}


GameManager::GameManager() {}
