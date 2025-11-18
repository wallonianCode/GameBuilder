#include "../Headers/MenuState.hpp"


void MenuState::process_events(bool& running, StateMachine* stateMachine,
VideoPlayer* videoPlayer) {
	//TODO ev: _nextState = nullptr; (because you return into it)
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				std::cout << "Menu State: quitting\n";
				_hasToBeRemoved = true;
				running = false;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.scancode) {
					case SDL_SCANCODE_ESCAPE:
					  std::cout << "Menu State: escaping\n";
						running = false;
						break;
					case SDL_SCANCODE_P:
						std::cout << "Adapting screen dimensions\n";
						videoPlayer->resize_screen(720, 480);
						break;
					default:
						std::cout << "Drawing Menu\n";
						//videoPlayer->set_drawing_mode(Mode::menu);
						break;
				}
			case SDL_MOUSEMOTION: 
				videoPlayer->highlight_menu_btn(event.motion);
				break;
			case SDL_MOUSEBUTTONDOWN: //TODO check if left or right
				videoPlayer->set_menu_btn_clicked(event.button);
				switch(videoPlayer->get_menu_btn_clicked()) {
					case MENU_BTN::build:
						_nextState = new BuildState();
						_hasToBeRemoved = false;	
						break;
					case MENU_BTN::play:
						_nextState = new PlayState();
						_hasToBeRemoved = false;
						break;
					case MENU_BTN::save:
						videoPlayer->save_build();
						_hasToBeRemoved = false;
						break;
					case MENU_BTN::exit: 
					  _nextState = new ExitState();
						_hasToBeRemoved = true;
						running = false; 
						break;
					default:
						break;
				}
				stateMachine->set_next_state();
			default:
				break;
		}
	}
}


void MenuState::update(VideoPlayer* vp) {
//	std::cout << "Menu State: updating\n";
}


void MenuState::draw(VideoPlayer* vp) {
	vp->draw_menu(); 
}
