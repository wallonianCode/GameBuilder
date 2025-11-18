#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "Window.hpp"
#include "Background.hpp"

class Renderer {
public:
	static Renderer* get_instance();
	SDL_Renderer* get_sdl_renderer();
	// reset the renderer with a uniform background of specified color
	void reset(Background*);
private:
	Renderer();
	void init(Window* window);
		
	SDL_Renderer* renderer_ = nullptr;
};


#endif
