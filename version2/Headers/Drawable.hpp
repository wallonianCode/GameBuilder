#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <memory>
#include "Renderer.hpp"
#include "Color.hpp"

const int STD_WIDTH = 4*S;
const int STD_HEIGHT = 4*S;


//TODO put here the constants for a standard tile size for example
class Drawable {
public:
	virtual void draw() = 0;
	virtual ~Drawable();
};



#endif
