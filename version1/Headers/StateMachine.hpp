#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <exception>
#include <stack>
#include <iostream>
#include "State.hpp"


//TODO go back from build/play to menu 
class State;

class StateMachine {
public:
	static StateMachine* get_instance();
	void initialize();

	State* get_active_state();
	void remove_active_state();
	void set_active_state(State* state);
  void set_next_state();

	StateMachine& operator=(const StateMachine&) = delete;
	StateMachine(const StateMachine&) = delete;

private: 
	StateMachine();	

	static StateMachine* _instance;
	std::stack<State*> _states;
};

#endif
