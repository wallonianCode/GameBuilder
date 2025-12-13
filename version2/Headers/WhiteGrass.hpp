#ifndef WHITEGRASS_H
#define WHITEGRASS_H

#include "SimpleTexture.hpp"

class WhiteGrass : public TextureCloneable<SimpleTexture, WhiteGrass> {
public:
    WhiteGrass(const SDL_FPoint&);
};

#endif
