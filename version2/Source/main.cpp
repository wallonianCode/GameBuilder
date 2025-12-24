#define SDL_MAIN_USE_CALLBACKS 1

#include <iostream>
#include <exception>

#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h> //TODO verify if not already included in main
#include <SDL3/SDL_main.h>

#include "../Headers/GameManager.hpp"


SDL_AppResult SDL_AppInit(void **appState, int argc, char *argv[]) {
	//TODO init windows & renderer
	//TODO set render performance window stuff
	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event* event) {
	return SDL_APP_SUCCESS;
}


SDL_AppResult SDL_AppIterate(void *appstate) {
  //TODO get game manager and run
	return SDL_APP_SUCCESS;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result) {

}




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
