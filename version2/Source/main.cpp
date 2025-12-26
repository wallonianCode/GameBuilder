#define SDL_MAIN_USE_CALLBACKS 1

#include <iostream>
#include <exception>

#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h> //TODO verify if not already included in main
#include <SDL3/SDL_main.h>

#include "../Headers/GameStateMachine.hpp"


SDL_AppResult SDL_AppInit(void **appState, int argc, char *argv[]) {
	// window & renderer are created by the game manager as part of 
	// the singleton logic.
	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event* event) {
	GameStateMachine* stateMachine;	
	bool stopGame;
	try {
		stateMachine = GameStateMachine::get_instance();
		stopGame = stateMachine->process_events();
	}
	catch (const std::runtime_error& err) {
		std::cerr << "Runtime error catched. Msg: " << 
		err.what() << " " << SDL_GetError() << std::endl;
	}
	std::cout << "main::SDL_AppEvent: " << stopGame << std::endl;
	return stopGame ? SDL_APP_SUCCESS : SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void *appstate) {
	GameStateMachine* stateMachine;
	//uint64_t start, end;
	//float elapsedS, elapsedMS;

	try {
		stateMachine = GameStateMachine::get_instance();
		stateMachine->update();
		stateMachine->draw();
	}
	catch(const std::runtime_error& err) {
		std::cout << "Runtime error catched. Msg: " << 
		err.what() << std::endl;	
	}
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result) {
}



/*
int main() {
	try {
		GameManager* gameManager = GameManager::get_instance();
		gameManager->run();
	}
	catch(const std::runtime_error& err) {
		std::cout << "Runtime error catched. Msg: " << err.what() << std::endl;	
	}

	return 0;
}
*/
