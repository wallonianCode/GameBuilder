#ifndef  POPLAR_H
#define  POPLAR_H

#include "CompositeTexture.hpp"

class Poplar : public TextureCloneable<CompositeTexture, Poplar> {
public:
	Poplar(const SDL_Point& initPos);
	static int get_width();
	static int get_height();
};

#endif
