#ifndef LAYERFACTORY_H
#define LAYERFACTORY_H

#include "Layer.hpp"
#include "RoadLayer.hpp"
#include "TreeLayer.hpp"
#include "SoilLayer.hpp"
#include "BuildingLayer.hpp"
#include "WaterLayer.hpp"
#include "BorderLayer.hpp"


class LayerFactory {
public:
    enum class LayerType {Road, Tree, Soil, Buildings, Water, Border};
    static Layer* create_layer(const int, const SDL_Point&,
							   const LayerFactory::LayerType&);
	static LayerFactory::LayerType get_next_layer_type(const LayerFactory::LayerType&);
	static LayerFactory::LayerType get_precedent_layer_type(const LayerFactory::LayerType&);
};

#endif
