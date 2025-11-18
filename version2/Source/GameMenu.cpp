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
GameState* GameMenu::handle_event(SDL_Event& event) {
	GameState *nextState = nullptr, *retour = nullptr;
	
	nextState = builderBtn_.handle_event(event);
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
	
	return retour;
}


GameMenu::GameMenu() {
/*
	Window* window = Window::get_instance();
	int xBtn = window->get_width()/3 + window->get_width()/12;
	int yIntervalBtn = window->get_height()/6;
	int widthBtn = window->get_width()/6;
	int heightBtn = window->get_height()/8;
	int frameThickness = window->get_width()/24;

	builderBtn_ = new BuilderButton({xBtn, window->get_height()/12}, 
	widthBtn, heightBtn, frameThickness, Color::brown4, Color::brown3); 

	playerBtn_ = new PlayerButton({xBtn, 
	window->get_height()/12 + yIntervalBtn}, widthBtn,
	heightBtn, frameThickness, Color::brown4, Color::brown3); 

	saveBtn_ = new SaveButton({xBtn, 
	window->get_height()/12 + 2*yIntervalBtn}, widthBtn,
	heightBtn, frameThickness, Color::brown4, Color::brown3); 

	exitBtn_ = new ExitButton({xBtn, 
	window->get_height()/12 + 3*yIntervalBtn}, widthBtn,
	heightBtn, frameThickness, Color::brown4, Color::brown3); 
	*/
  
}
