#ifndef  HORNBEAM_H
#define  HORNBEAM_H

#include "CompositeTexture.hpp"

class Hornbeam : public TextureCloneable<CompositeTexture, Hornbeam> {
public:
	Hornbeam(const SDL_Point& initPos);
	static int get_width();
	static int get_height();
};

#endif
