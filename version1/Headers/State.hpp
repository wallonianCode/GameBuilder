#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "StateMachine.hpp"
#include "VideoPlayer.hpp"
#include "TextureLoader.hpp"

class StateMachine;


class State {
public:
  State();
	virtual void process_events(bool&, StateMachine*, VideoPlayer*) = 0;
	virtual void update(VideoPlayer*) = 0;
	virtual void draw(VideoPlayer*) = 0;
  
	virtual bool has_to_be_removed();
	virtual State* get_next_state();
protected:
	State* _nextState = nullptr;
	bool _hasToBeRemoved = false;
};

#endif
