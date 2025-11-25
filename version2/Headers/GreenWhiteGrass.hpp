#ifndef GREENWHITEGRASS_H
#define GREENWHITEGRASS_H

#include "SimpleTexture.hpp"

class GreenWhiteGrass : public TextureCloneable<SimpleTexture, GreenWhiteGrass> {
public:
    GreenWhiteGrass(const SDL_Point&);
};
#endif