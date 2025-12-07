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
	std::cout << "GameStateMachine::handle_frame(): taking up the top " <<
	(states_.size()) << std::endl;
	currentState = states_.top();

	nextState = currentState->process_events(running);
	std::cout << "GameStateMachine::handle_frame(): " << 
	(nextState == nullptr) << std::endl; 
	currentState->update();
	currentState->draw();	
	std::cout << "GameStateMachine::handle_frame() " <<
	"After having drawn and updated the current state, stack size: " <<
	(states_.size()) << std::endl;
	

	renderer->print();

	if (! running) {
		states_.pop();
	}

	if (nextState != nullptr) {
		std::cout << "GameStateMachine::handle_frame(): new state has been\
		pushed" << std::endl;
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
