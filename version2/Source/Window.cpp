#include "../Headers/Window.hpp"

Window* Window::instance_ = nullptr;


Window* Window::get_instance() {
	if (! instance_) instance_ = new Window();
	return instance_;
}


void Window::move(const SDL_Point& posOnScreen) {
	SDL_SetWindowPosition(window_, posOnScreen.x, posOnScreen.y);
}


void Window::move_rel(const SDL_Point& posOnScreen) {
	int x, y;
	SDL_GetWindowPosition(window_, &x, &y);
	SDL_SetWindowPosition(window_, x+posOnScreen.x, y+posOnScreen.y);
}


void Window::set_dimensions(const int width, const int height) {
	std::cout << "Window::set_dimensions(): width " << width <<
	"Height: " << height << std::endl;
	SDL_SetWindowSize(window_, width, height);	
}


void Window::set_width(const int& width) {
	int w, h;
	std::cout << "Window::set_width: " << width << std::endl;
	SDL_GetWindowSize(window_, &w, &h);
	SDL_SetWindowSize(window_, width, h);
}


void Window::set_height(const int& height) {
	int w, h;
	SDL_GetWindowSize(window_, &w, &h);
	SDL_SetWindowSize(window_, w, height);
}


SDL_Window* Window::get_sdl_window() {
	return window_;
}


int Window::get_width() {
	int w, h;
	SDL_GetWindowSize(window_, &w, &h);
	return w;
}

int Window::get_height() {
	int w, h;
	SDL_GetWindowSize(window_, &w, &h);
	return h;
}

Window::Window() {
	//int imgFlags = IMG_INIT_PNG;
	
	// init SDL_Window	
	window_ = SDL_CreateWindow(WINDOW_TITLE.c_str(), 
	WINDOW_WIDTH, WINDOW_HEIGHT,
	SDL_WINDOWPOS_CENTERED | SDL_WINDOWPOS_CENTERED);
	if (! window_) {
		std::printf("SDL_Window could not be created: %s\n", SDL_GetError());
		throw std::runtime_error("Player::init(): failed window init");
	}

	// init SDL_Image
	// instead of setHint
	//SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
/* 
	if( !( IMG_Init(imgFlags) & imgFlags))
    {
		std::printf( "SDL_image could not initialize! SDL_image\
		Error: %s\n", IMG_GetError() );
		throw std::runtime_error("Player::init(): failed sdl_image init");
	}
*/
	// init TTF_Fonts
	if (!TTF_Init()) {
  		std::cout << __FUNCTION__ << SDL_GetError() << std::endl;
	}
}
