#ifndef ROCK_H
#define ROCK_H

#include "SimpleTexture.hpp"


class Rock : public TextureCloneable<SimpleTexture, Rock> {
public:
	Rock(const SDL_FPoint&);
};

#endif
