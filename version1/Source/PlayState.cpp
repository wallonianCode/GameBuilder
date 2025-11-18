#include "../Headers/PlayState.hpp"

PlayState::PlayState() {
	_delay = 0;
	_max = 3;
	_npcTick = 0;
	_npcClockOverflow = 30;		
}


void PlayState::process_events(bool& running, StateMachine* stateMachine, 
VideoPlayer* vp) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		//_delay++;
		//if (_delay < _max) return;
		//else reset();
		switch(event.type) {
			case SDL_QUIT:
				std::cout << "Quitting play state" << std::endl;
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode) {
					case SDL_SCANCODE_ESCAPE:
						_hasToBeRemoved = true;
						stateMachine->set_next_state();
						break;
					case SDL_SCANCODE_A: //Q
						//vp->increment_play_horizontal_shift();
						vp->move_landscape_east();	
						vp->move_trainer_west();
						break;
					case SDL_SCANCODE_S: //S
						//vp->increment_play_vertical_shift();
						vp->move_landscape_north();
						vp->move_trainer_south();
						break;
					case SDL_SCANCODE_D: //D
						//vp->decrement_play_horizontal_shift();
						vp->move_landscape_west();
						vp->move_trainer_east();
						break;
					case SDL_SCANCODE_W: //Z
						//vp->decrement_play_vertical_shift();
						vp->move_landscape_south();
						vp->move_trainer_north();
						break;
					default:
						break;
				}
			case SDL_KEYUP:
				switch (event.key.keysym.scancode) {
					case SDL_SCANCODE_W:
					case SDL_SCANCODE_A:
					case SDL_SCANCODE_D:
					case SDL_SCANCODE_S:
						//vp->set_trainer_still();
						break;
					default:
						break;
				}
			default:
				break;
		}
	}
}


void PlayState::update(VideoPlayer* vp) {
	if (_npcTick == _npcClockOverflow) {
		vp->update_npcs(); 
		_npcTick = 0;
	}
	else {
		_npcTick++;
	}
}


void PlayState::draw(VideoPlayer* vp) {
	vp->draw_play();
}


bool PlayState::is_max() {
	return (_delay >= _max);
}


void PlayState::reset() {
	if (is_max()) {
		_delay = 0;
	}
}
