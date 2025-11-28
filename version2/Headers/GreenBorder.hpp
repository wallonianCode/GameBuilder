#ifndef GREENBORDER_H
#define GREENBORDER_H

#include "DeclinedTexture.hpp"


class GreenBorder : public TextureCloneable<DeclinedTexture, GreenBorder> {
public:
	GreenBorder(const SDL_FPoint&, const DeclinedTextureOrientation&);
};


#endif
