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


class DeclinedTexture : public TextureCloneable<SimpleTexture, DeclinedTexture>{
public:
	DeclinedTexture();
	DeclinedTexture(const SDL_FPoint& pos);
};

#endif
