#include "../Headers/GameMenu.hpp"


void GameMenu::draw() {
	background_.draw();
	builderBtn_.draw();
	playerBtn_.draw();
	saveBtn_.draw();
	exitBtn_.draw();
	
}


void GameMenu::update() {}


// one possibility to avoid returning null ptr would be to implement
// a 'blank' state with operator == overloaded
// nextState == blankState and you would need a comparator
GameState* GameMenu::handle_event(SDL_Event* event) {
	GameState *nextState; //*retour;
	//retour = nullptr;
	nextState = builderBtn_.handle_event(event);
	/*
	if (nextState != nullptr) {
		retour = nextState;
	}

	nextState =	playerBtn_.handle_event(event);
	if (nextState != nullptr) {
		retour = nextState;
	}

	nextState = saveBtn_.handle_event(event);
	if (nextState != nullptr) {
		retour = nextState;
	}

	nextState = exitBtn_.handle_event(event);
	if (nextState != nullptr) {
		retour = nextState;
	}
		*/
	//nextState->update();
	//std::cout << (nextState == nullptr) << std::endl;
	return nextState;
}


GameMenu::GameMenu() {
}
