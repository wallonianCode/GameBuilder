#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include <iostream>
#include <SDL2/SDL.h>

#include "State.hpp"


class PlayState : public State {
public:
	PlayState();
	void process_events(bool&, StateMachine*, VideoPlayer*) override;
	void update(VideoPlayer*) override;
	void draw(VideoPlayer*) override;
private:
	bool is_max();
	void reset();
	int _delay;
	int _max;
	int _npcTick;
	int _npcClockOverflow;
};

#endif
