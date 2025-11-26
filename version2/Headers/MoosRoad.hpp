#ifndef MOOSROAD_H
#define MOOSROAD_H


#include "DeclinedTexture.hpp"


class MoosRoad : public TextureCloneable<DeclinedTexture, MoosRoad> {
public:
	MoosRoad(const SDL_Point&,
			 const DeclinedTextureOrientation& orientation);
};
#endif
