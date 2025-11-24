#ifndef SOILLAYER_H
#define SOILLAYER_H

#include "Layer.hpp"

//TODO build a grass factory
class SoilLayer : public Layer {
public:
    SoilLayer(const int, const SDL_Point&);
};
#endif