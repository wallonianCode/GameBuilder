#ifndef  POPLAR_H
#define  POPLAR_H

#include "CompositeTexture.hpp"

class Poplar : public TextureCloneable<CompositeTexture, Poplar> {
public:
	Poplar(const SDL_Point& initPos);
};

#endif
