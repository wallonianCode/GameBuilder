#include "../Headers/GameStateMachine.hpp"

GameStateMachine* GameStateMachine::instance_ = nullptr;


GameStateMachine* GameStateMachine::get_instance() {
	if (! instance_) instance_ = new GameStateMachine();
	return instance_;
}


bool GameStateMachine::handle_frame() {
	Renderer* renderer = Renderer::get_instance();
	bool stopGame = false, running = true;
	GameState* currentState = states_.top();
	GameState* nextState = currentState->process_events(running);
//	std::cout << "Events processed for the next state" << std::endl;
	currentState->update();
//	std::cout << "Current state updated" << std::endl;
	currentState->draw();	
//	std::cout << "Current state drawn" << std::endl;
	renderer->print();
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
//		std::cout << "Pushing the next state" << std::endl;
		nextState->update();
//		std::cout << "Calling update() function on next state" <<
//		std::endl;
	}
	else { //nextState==nullptr && running
		//std::cout << "Keep the menu" << std::endl;	
	}
	return stopGame;
}


GameStateMachine::GameStateMachine() {
	states_.push(new GameMenuState());	
}
