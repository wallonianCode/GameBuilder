#ifndef GREENGRASS_H 
#define GREENGRASS_H

#include "SimpleTexture.hpp"

class GreenGrass : public TextureCloneable<SimpleTexture, GreenGrass> {
public: 
    GreenGrass(const SDL_Point&);
};

#endif