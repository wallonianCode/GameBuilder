#ifndef EXIT_STATE
#define EXIT_STATE

#include <iostream>
#include <SDL2/SDL.h>
#include "State.hpp"

class ExitState : public State {
public:
	ExitState();
	void process_events(bool&, StateMachine*, VideoPlayer*) override;
	void update(VideoPlayer*) override;
	void draw(VideoPlayer*) override;

};

#endif
