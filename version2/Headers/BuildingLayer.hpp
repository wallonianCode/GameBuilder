#ifndef  BUILDINGLAYER_H
#define  BUILDINGLAYER_H

#include "SimpleTexture.hpp"

class BuildingLayer : public TextureCloneable<SimpleTexture, BuildingLayer> {
public:
    BuildingLayer(const SDL_Point&);
};

#endif