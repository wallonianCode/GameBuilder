#ifndef SAND_H
#define SAND_H


#include "LeafGreenTexture.hpp"

class Sand : public TextureCloneable<LeafGreenTexture, Sand> {
public:
	Sand(const SDL_Point&);
};

#endif
