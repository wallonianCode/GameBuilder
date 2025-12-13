#ifndef GREENWHITEGREENGRASS_H
#define GREENWHITEGREENGRASS_H

#include "SimpleTexture.hpp"

class GreenWhiteGreenGrass : public TextureCloneable<SimpleTexture, GreenWhiteGreenGrass> {
public:
    GreenWhiteGreenGrass(const SDL_FPoint&);
};
#endif
