#ifndef LAYERFACTORY_H
#define LAYERFACTORY_H

#include "Layer.hpp"
#include "RoadLayer.hpp"
#include "TreeLayer.hpp"
#include "SoilLayer.hpp"
#include "BuildingsLayer.hpp"
#include "WaterLayer.hpp"
#include "BorderLayer.hpp"


class LayerFactory {
public:
    enum class LayerType {Road, Tree, Soil, Buildings, Water, Border};
    static Layer* create_layer(const LayerFactory::LayerType&);
		LayerType operator++(const LayerType&, int); //postfix
		LayerType operator++(const LayerType&);
		LayerType operator--(const LayerType&, int);
		LayerType operator--(const LayerType&);
};

#endif
