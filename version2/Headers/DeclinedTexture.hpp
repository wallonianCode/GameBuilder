#ifndef DECLINEDTEXTURE_H
#define DECLINEDTEXTURE_H

#include "SimpleTexture.hpp"


enum class DeclinedTextureOrientation {
	North,
	West,
	East,
	South,
	NorthWest,
	NorthEast,
	SouthWest,
	SouthEast, 
	Center,
	NorthWestCorner,
	NorthEastCorner,
	SouthEastCorner,
	SouthWestCorner
};


class DeclinedTexture : public SimpleTexture {
public:
	DeclinedTexture(const SDL_Point& pos);
};

#endif
