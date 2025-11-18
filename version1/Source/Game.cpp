#include "../Headers/Game.hpp"

Game* Game::_instance = nullptr;

Game* Game::get_instance() {
	if (! Game::_instance) {
		Game::_instance = new Game();
	}
	return Game::_instance;
}


void Game::initialize() {
  this->_stateMachine = StateMachine::get_instance();
	this->_stateMachine->set_active_state(new MenuState());
	this->_videoPlayer->initialize();
}


void Game::run() {
	std::cout << "Game is running\n";
	bool running = true;
	while (running) {
	  State* currentState = this->_stateMachine->get_active_state();
		std::cout << "State taken out of the state machine" << std::endl;
		if (! currentState) {
			throw std::runtime_error("Game::run(): current state is null!");
		}
		currentState->process_events(running, 
		this->_stateMachine, this->_videoPlayer);
		std::cout << "Game::run() event processed" << std::endl;
		currentState->update(this->_videoPlayer);	
		std::cout << "Game::run() updated" << std::endl;
		currentState->draw(_videoPlayer);
//		SDL_Delay(2);
	}
}


Game::~Game() {
	TextureLoader::deallocate_textures();
}


Game::Game() {
	std::cout << "Game created" << std::endl;
	_videoPlayer = VideoPlayer::get_instance();
}
