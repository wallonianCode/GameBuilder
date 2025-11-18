#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "Renderer.hpp"
#include "GameState.hpp"
#include "GameMenuState.hpp"
#include <stack>

// manage states
class GameStateMachine {
public:
	static GameStateMachine* get_instance();
	
	// returns true if there is still a state running
	bool handle_frame();
	
	GameStateMachine& operator=(const GameStateMachine&) = delete;
	GameStateMachine(const GameStateMachine&) = delete;
private:
	GameStateMachine();
	static GameStateMachine* instance_;
	std::stack<GameState*> states_;
};


#endif
