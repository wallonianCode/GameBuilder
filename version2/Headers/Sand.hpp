#ifndef SAND_H
#define SAND_H


#include "SimpleTexture.hpp"

class Sand : public TextureCloneable<SimpleTexture, Sand> {
public:
	Sand(const SDL_Point&);
};

#endif
