#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Drawable.hpp"
#include "Color.hpp"

class Background : public Drawable {
public: 
	virtual void draw();
	Background(const SDL_Color& color);
private:
	SDL_Color color_;
};


#endif
