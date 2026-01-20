#ifndef MOOSROAD_H
#define MOOSROAD_H


#include "DeclinedTexture.hpp"


class MoosRoad : public TextureCloneable<DeclinedTexture, MoosRoad> {
public:
	MoosRoad(const SDL_FPoint&,
			 const DeclinedTextureOrientation& orientation);
};
#endif
