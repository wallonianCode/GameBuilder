#include "../Headers/ExitState.hpp"


ExitState::ExitState() {
	std::cout << "Entering the exit state" << std::endl;
}


void ExitState::process_events(bool& running, StateMachine* sm, VideoPlayer* vp) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				std::cout << "Exit State: quitting" << std::endl;
				_hasToBeRemoved = true;
				running = false;
				break;
			default:
				break;
		}
	}
}



void ExitState::update(VideoPlayer* vp) {
}


void ExitState::draw(VideoPlayer* vp) {
	vp->draw_exit();
}
