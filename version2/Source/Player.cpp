#include "../Headers/Player.hpp"

Player* Player::instance_ = nullptr;


Player* Player::get_instance() {
	if (! instance_) instance_ = new Player();
	return instance_;
}

void Player::init() {}

/*
void Player::init() {
	// init SDL_Window	
	window_ = SDL_CreateWindow(WINDOW_TITLE.c_str(), 
	SDL_WINDOWPOS_CENTERED, 
	SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (! window_) {
		std::printf("SDL_Window could not be created: %s\n", SDL_GetError());
		throw std::runtime_error("Player::init(): failed window init");
	}
	
	// init SDL_Renderer
	renderer_ = SDL_CreateRenderer(window_, -1, 
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PREVENTVSYNC | 
	SDL_RENDERER_TARGETTEXTURE);
	if (! renderer_) {
		std::cout << SDL_GetError() << std::endl;
		throw std::runtime_error("Player::init(): failed renderer init");
	}

  // init SDL_Image
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init(imgFlags) & imgFlags))
  {
		std::printf( "SDL_image could not initialize! SDL_image\
		Error: %s\n", IMG_GetError() );
		throw std::runtime_error("Player::init(): failed sdl_image init");
	}
}
*/


Player::Player() {
	this->init();
}
