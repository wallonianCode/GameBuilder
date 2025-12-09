#include "../Headers/GameStateMachine.hpp"

GameStateMachine* GameStateMachine::instance_ = nullptr;


GameStateMachine* GameStateMachine::get_instance() {
	if (! instance_) instance_ = new GameStateMachine();
	return instance_;
}


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


	/*
	if (nextState != nullptr && !running) {
		states_.pop();
		states_.push(nextState);
	}
	else if (nextState == nullptr && !running) { 
		states_.pop();
		if (states_.empty()) stopGame = true;
	}
	else if (nextState != nullptr && running) { 
		states_.push(nextState);
		nextState->update();
	}
	else { //nextState==nullptr && running
		//stay in the same state
	}
		*/
	return stopGame;
}


GameStateMachine::GameStateMachine() {
	states_.push(new GameMenuState());	
}
