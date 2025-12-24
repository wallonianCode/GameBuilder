#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

#include "Window.hpp"


class Renderer {
public:
	static Renderer* get_instance();
	SDL_Renderer* get_sdl_renderer();
	void print();
	// reset the renderer with a uniform background of specified color
//	void reset(Background*);
private:
	Renderer();
	void init(Window* window);
	static Renderer* instance_;		
	SDL_Renderer* renderer_;
};


#endif
