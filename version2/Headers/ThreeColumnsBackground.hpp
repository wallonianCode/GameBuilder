#ifndef THREECOLUMNSBACKGROUND_H
#define THREECOLUMNSBACKGROUND_H

#include "Background.hpp"
#include "Rectangle.hpp"

class ThreeColumnsBackground : public Background {
public:
	void draw() override;
	ThreeColumnsBackground(const SDL_Color& backColor, 
	const SDL_Color& foreColor);
private:
	SDL_Color foregroundColor_;
};

#endif
