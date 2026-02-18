#include "../Headers/Pin.hpp"


Pin::Pin(std::vector<SDL_FRect>::iterator itSrcBegin,
		std::vector<SDL_FRect>::iterator itSrcEnd,
		std::vector<SDL_FRect>::iterator itDestBegin,
		std::vector<SDL_FRect> ::iterator itDestEnd) :
		CompositeTexture(leafGreenTextureFileName, itSrcBegin, itSrcEnd, itDestBegin, itDestEnd) {}


float Pin::get_width() const {
	return 2*TILE_DIM; 
}

float Pin::get_height() const {
	return 3*TILE_DIM;
}
