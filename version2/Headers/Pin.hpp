#ifndef PIN_H
#define PIN_H

#include "CompositeTexture.hpp"

class Pin : public TextureCloneable<CompositeTexture, Pin> {
public:
	Pin(const SDL_FPoint& initPos);
};


#endif
