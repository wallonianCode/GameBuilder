#ifndef WATERLAYER_H
#define WATERLAYER_H

#include "Layer.hpp"


class WaterLayer : public Layer {
public:
    WaterLayer(const int, const SDL_FPoint&);
};

#endif 
