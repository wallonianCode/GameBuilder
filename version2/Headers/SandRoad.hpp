#ifndef SANDROAD_H
#define SANDROAD_H

#include "Road.hpp"

class SandRoad : public TextureCloneable<DeclinedTexture, SandRoad> {
public:
	SandRoad(const SDL_Point&, const DeclinedTextureOrientation&);
};
#endif
