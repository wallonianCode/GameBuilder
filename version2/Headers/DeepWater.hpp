#ifndef DEEPWATER_H
#define DEEPWATER_H

#include "DeclinedTexture.hpp"


class DeepWater : public TextureCloneable<DeclinedTexture, DeepWater> {
public:
	DeepWater(const SDL_Point&, 
						const DeclinedTextureOrientation&);
};
#endif

