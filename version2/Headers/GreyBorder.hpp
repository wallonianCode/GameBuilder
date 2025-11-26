#ifndef GRAY_BORDER_H
#define GRAY_BORDER_H

#include "DeclinedTexture.hpp"

class GreyBorder : public TextureCloneable<DeclinedTexture, GreyBorder> {
public:
	GreyBorder(const SDL_Point&, const DeclinedTextureOrientation&);
};


#endif
