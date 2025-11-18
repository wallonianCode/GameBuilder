#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <iostream>
#include "State.hpp"
#include "VideoPlayer.hpp"
#include "BuildState.hpp"
#include "PlayState.hpp"
#include "ExitState.hpp"


//TODO maybe a draw menu member
class MenuState : public State {
public:
	void process_events(bool&,StateMachine*, VideoPlayer*) override;
	void update(VideoPlayer*) override;
	void draw(VideoPlayer*) override;

};

#endif
