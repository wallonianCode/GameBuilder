#ifndef PIN_H
#define PIN_H

#include "CompositeTexture.hpp"

class Pin : public TextureCloneable<CompositeTexture, Pin> {
public:
	Pin(std::vector<SDL_FRect>::iterator itSrcBegin,
		std::vector<SDL_FRect>::iterator itSrcEnd,
		std::vector<SDL_FRect>::iterator itDestBegin,
		std::vector<SDL_FRect> ::iterator itDestEnd);

	static float get_width();
	static float get_height();
};


#endif
