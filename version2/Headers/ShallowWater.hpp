#ifndef SHALLOWWATER_H
#define SHALLOWWATER_H

#include "DeclinedTexture.hpp"


class ShallowWater : public TextureCloneable<DeclinedTexture, ShallowWater> {
public:
	ShallowWater(const SDL_Point&, const DeclinedTextureOrientation&);

};
#endif
