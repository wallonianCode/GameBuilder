#ifndef BORDERLAYER_H
#define BORDERLAYER_H


#include "Layer.hpp"

class BorderLayer : public Layer {
public:
    BorderLayer(const int, const SDL_FPoint&);
};
#endif