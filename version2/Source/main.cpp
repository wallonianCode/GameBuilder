#include <iostream>
#include <exception>
#include <SDL3/SDL.h>
#include "../Headers/GameManager.hpp"


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
