#ifndef TALLGRASS_H
#define TALLGRASS_H

#include "SimpleTexture.hpp"


class TallGrass : public TextureCloneable<SimpleTexture, TallGrass> {
public:
	TallGrass(const SDL_FPoint&);
};



#endif
