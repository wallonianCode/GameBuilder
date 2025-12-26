#include "../Headers/GameStateMachine.hpp"

GameStateMachine* GameStateMachine::instance_ = nullptr;


GameStateMachine* GameStateMachine::get_instance() {
	if (! instance_) instance_ = new GameStateMachine();
	return instance_;
}

/*
bool GameStateMachine::handle_frame() {
	Renderer* renderer;
	GameState* currentState,
			 * nextState;
	bool stopGame, running;


	renderer = Renderer::get_instance();
	stopGame = false;
  running = true;
	currentState = states_.top();

	nextState = currentState->process_events(running);
	currentState->update();
	currentState->draw();	

	renderer->print();

	if (! running) {
		states_.pop();
	}

	if (nextState != nullptr) {
		states_.push(nextState);
	}

	if (states_.empty()) {
		stopGame = true;
	}
	return stopGame;
}
*/


bool GameStateMachine::process_events() {
	GameState *currentState, *nextState;
	bool stopGame, running;

	stopGame = false;
	currentState = states_.top();
	nextState = currentState->process_events(running);

	if (! running) {
		states_.pop();
	}

	if (nextState != nullptr) {
		states_.push(nextState);
	}

	if (states_.empty()) {
		stopGame = true;
	}
	return stopGame;
}


void GameStateMachine::update() {
	GameState* currentState;

	currentState = states_.top();
	currentState->update();
}

void GameStateMachine::draw() {
	GameState* currentState;

	currentState = states_.top();
	currentState->draw();
}


GameStateMachine::GameStateMachine() {
	states_.push(new GameMenuState());	
}
