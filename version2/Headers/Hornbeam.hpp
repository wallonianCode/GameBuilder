#ifndef  HORNBEAM_H
#define  HORNBEAM_H

#include "CompositeTexture.hpp"

class Hornbeam : public TextureCloneable<CompositeTexture, Hornbeam> {
public:
	Hornbeam(const SDL_FPoint& initPos);
};

#endif
