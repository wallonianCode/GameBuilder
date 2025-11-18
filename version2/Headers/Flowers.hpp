#ifndef FLOWERS_H
#define FLOWERS_H

#include "SimpleTexture.hpp"


class Flowers : public TextureCloneable<SimpleTexture, Flowers> {
public:
	Flowers(const SDL_Point&);
};

#endif
