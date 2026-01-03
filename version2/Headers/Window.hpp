#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_video.h>

#include <string>
#include <iostream>

const int S = 17;
const int TILE_DIM = 4*S;
const std::string WINDOW_TITLE = "Game Builder";
const int WINDOW_WIDTH = 25*TILE_DIM; 
const int WINDOW_HEIGHT = 20*TILE_DIM;


class Window {
public:
	static Window* get_instance();
	// move window to given absolute position
	void move(const SDL_Point&);
	// move window to given relative position
	void move_rel(const SDL_Point&);
	// reset window dimensions
	void set_dimensions(const int, const int);
	void set_width(const int);
	void set_height(const int);
	
	SDL_Window* get_sdl_window();	
	int get_width();
	int get_height();
private:
	Window();
	static Window* instance_;
	SDL_Window* window_;
};

#endif
