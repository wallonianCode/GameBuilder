#ifndef SANDROAD_H
#define SANDROAD_H

#include "DeclinedTexture.hpp"

class SandRoad : public TextureCloneable<DeclinedTexture, SandRoad> {
public:
	SandRoad(const SDL_FPoint&, const DeclinedTextureOrientation&);
};
#endif
