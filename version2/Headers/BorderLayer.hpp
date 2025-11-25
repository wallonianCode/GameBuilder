#ifndef BORDERLAYER_H
#define BORDERLAYER_H


#include "Layer.hpp"

class BorderLayer : public TextureCloneable<Layer, BorderLayer> {
public:
    BorderLayer(const int, const SDL_Point&);
};
#endif