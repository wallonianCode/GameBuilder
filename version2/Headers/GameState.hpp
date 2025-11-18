#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>


class GameState {
public:
	// modify the inner state of the map as a function of events 
	// running = false: the state has to be removed from the state machine
	// returns the next state, or nullptr if the game remains in this state
	virtual GameState* process_events(bool& running) = 0; 
	// change the inner state of the map as a function of inner counters
	virtual void update() = 0;
	// load the modified map into the renderer
	virtual void draw() = 0;	
};

#endif
