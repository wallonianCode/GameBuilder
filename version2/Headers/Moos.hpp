#ifndef MOOS_H
#define MOOS_H

#include "SimpleTexture.hpp"


class Moos : public TextureCloneable<SimpleTexture, Moos> {
public:
	Moos(const SDL_FPoint&);
};

#endif
