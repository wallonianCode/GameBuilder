#ifndef  BUILDINGLAYER_H
#define  BUILDINGLAYER_H

#include "Layer.hpp"

class BuildingLayer : public TextureCloneable<Layer, BuildingLayer> {
public:
    BuildingLayer(const int, const SDL_Point&);
};

#endif