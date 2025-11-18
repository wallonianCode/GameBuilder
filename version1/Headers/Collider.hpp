#ifndef COLLIDER_H
#define COLLIDER_H

#include <SDL2/SDL.h>
#include <iostream>


class Collider {
public:
	Collider();
	static bool is_mouse_inside_frame(const SDL_MouseMotionEvent&, 
	const SDL_Rect&);
	static bool is_click_inside_frame(const SDL_MouseButtonEvent&, 
	const SDL_Rect&);
};

#endif
