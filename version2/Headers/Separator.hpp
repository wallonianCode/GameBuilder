#ifndef SEPARATOR_H
#define SEPARATOR_H

#include "Drawable.hpp"
#include "Bush.hpp"


class Separator : public Drawable {
public:
	void draw();
	void handle_event(SDL_Event* event);
	bool is_mouse_in();
	Separator();
private:
	std::vector<Texture*> vTextures;
	const float xBegin_ = 5*TILE_DIM;
	const float xEnd_ = 7*TILE_DIM;
};


#endif
