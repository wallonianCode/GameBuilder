#include "../Headers/StateMachine.hpp"
#include "../Headers/MenuState.hpp"


StateMachine* StateMachine::_instance = nullptr;

StateMachine* StateMachine::get_instance() {
	if (! StateMachine::_instance) {
		StateMachine::_instance = new StateMachine();
	}
	return StateMachine::_instance;
}


void StateMachine::initialize() {
	this->_states.push(new MenuState());
}


StateMachine::StateMachine() {}


State* StateMachine::get_active_state() {
	std::cout << "StateMachine::get_active_state() -- 1" << std::endl;
	std::cout << "Accessing states*" << this->_states.empty() << std::endl;
  if (this->_states.empty()) {
		throw 
		std::runtime_error("SM::get_active_state : State machine is empty\n");
	}
	std::cout << "StateMachine::get_active_state() -- 2" << std::endl;
	return this->_states.top();
}


void StateMachine::remove_active_state() {
  if (this->_states.empty()) {
		throw std::runtime_error("SM::pop : State machine is empty\n"); 
	}
	else {
		this->_states.pop();
	}
}


void StateMachine::set_active_state(State* state) {
  if (! state) {
		throw 
		std::runtime_error("StateMachine::set_active_state: state is null");
	}
	std::cout << "New active state set" << std::endl;
	this->_states.push(state);	
}


//TODO this function serves multiple purposes and is unclear
void StateMachine::set_next_state() {
	std::cout << "Stack size: " << _states.size() << std::endl;
  State* currentState;
	(! _states.empty()) ? currentState = get_active_state() : 
	throw std::runtime_error("SM::set_next_state: stack is empty!");
	State* nextState = currentState->get_next_state();
  if (nextState) {
	  std::cout << "SM::set_next_state(): next state is not null!" 
		<< std::endl;
		if (currentState->has_to_be_removed()) {
			this->remove_active_state();
		}
		this->set_active_state(nextState);
	}
	else if (currentState->has_to_be_removed()) {
		this->remove_active_state();
	}
}
