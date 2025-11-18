#ifndef SMALLTREE_H
#define SMALLTREE_H

#include "SimpleTexture.hpp"


class SmallTree : public TextureCloneable<SimpleTexture, SmallTree> {
public:
	SmallTree(const SDL_Point&);
};


#endif
