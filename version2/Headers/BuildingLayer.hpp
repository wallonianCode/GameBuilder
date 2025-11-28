#ifndef  BUILDINGLAYER_H
#define  BUILDINGLAYER_H

#include "Layer.hpp"

class BuildingLayer : public Layer {
public:
    BuildingLayer(const int, const SDL_Point&);
};

#endif