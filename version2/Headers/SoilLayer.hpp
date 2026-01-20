#ifndef SOILLAYER_H
#define SOILLAYER_H

#include "Layer.hpp"


class SoilLayer : public Layer {
public:
    SoilLayer(const int, const SDL_FPoint&);
};
#endif