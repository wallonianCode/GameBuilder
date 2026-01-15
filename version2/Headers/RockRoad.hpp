#ifndef ROCKROADTEXTURE_H
#define ROCKROADTEXTURE_H

#include "DeclinedTexture.hpp"


class RockRoad : public TextureCloneable<DeclinedTexture, RockRoad> {
public:
	RockRoad(const SDL_FPoint&, const DeclinedTextureOrientation&);
	RockRoad(const RockRoad&);
};


#endif
