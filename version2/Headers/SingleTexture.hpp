#ifndef SINGLE_TEXTURE_H
#define SINGLE_TEXTURE_H

#include <string>
#include "LeafGreenTexture.hpp"

/* 
 * for textures that are not declined in different tiles like roads
 */


class SingleTexture : 
public TextureCloneable<LeafGreenTexture, SingleTexture> {
public:
	SingleTexture(const SDL_Point&);
	void update() override;

};


#endif
