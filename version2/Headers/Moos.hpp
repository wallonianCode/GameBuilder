#ifndef MOOS_H
#define MOOS_H

#include "SimpleTexture.hpp"


class Moos : public TextureCloneable<LeafGreenTexture, Moos> {
public:
	Moos(const SDL_Point&);
};

#endif
