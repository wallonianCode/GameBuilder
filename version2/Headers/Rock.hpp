#ifndef ROCK_H
#define ROCK_H

#include "LeafGreenTexture.hpp"


class Rock : public TextureCloneable<LeafGreenTexture, Rock> {
public:
	Rock(const SDL_Point&);
};

#endif
