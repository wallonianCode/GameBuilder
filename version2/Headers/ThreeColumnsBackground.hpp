#ifndef THREECOLUMNSBACKGROUND_H
#define THREECOLUMNSBACKGROUND_H

#include "Rectangle.hpp"

class ThreeColumnsBackground : public Drawable {
public:
	void draw() override;
	ThreeColumnsBackground(const SDL_Color& backColor, const SDL_Color& foreColor);
private:
	SDL_Color backgroundColor_, foregroundColor_;

	
};

#endif