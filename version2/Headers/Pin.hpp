#ifndef PIN_H
#define PIN_H

#include "CompositeTexture.hpp"

class Pin : public TextureCloneable<CompositeTexture, Pin> {
public:
	Pin(const SDL_Point& initPos);
	static int get_width();
	static int get_height();
};


#endif
