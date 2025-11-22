#include "../Headers/LayerFactory.hpp"


LayerFactory::create_layer(const LayerFactory::LayerType& layerType) {
	Layer* newLayer;
	newLayer = nullptr;
	switch (layerType) {
			case LayerFactory::LayerType::Roads: {
					newLayer = new RoadLayer(width_);
					break;
			}
			case LayerFactory::LayerType::Trees: {
					newLayer = new TreeLayer(width_);
					break;
			}
			case LayerFactory::LayerType::Soil: {
					newLayer = new SoilLayer(width_);
					break;
			}
			case LayerFactory::LayerType::Buildings: {
					newLayer = new BuildingLayer(width_);
					break;
			}
			default: {
				throw 
				std::runtime_error("Layer type not recognized: " + layerType);
				break;
			}
    }
	}
	return newLayer;
}


LayerType LayerFactory::operator++(
LayerFactory::LayerType& layerType, int dummy) {
	int layerTypeNb;
	LayerType layerTypeInitCopy;

	layerTypeInitCopy = layerType;
	layerTypeNb = static_cast<int>(layerType);
	++layerTypeNb;
	layerType = static_cast<LayerFactory::LayerType>(layerTypeNb);

	return layerTypeInitCopy;
}


LayerType LayerFactory::operator++(
LayerFactory::LayerType& layerType) {
	int layerTypeNb;

	layerTypeNb = static_cast<int>(layerType);
	++layerTypeNb;
	layerType = static_cast<LayerFactory::LayerType>(layerTypeNb);

	return layerType;
}


LayerType LayerFactory::operator--(
LayerFactory::LayerType& layerType, int dummy) {
	int layerTypeNb;
	LayerType layerTypeInitCopy;

	layerTypeInitCopy = layerType;
	layerTypeNb = static_cast<int>(layerType);
	--layerTypeNb;
	layerType = static_cast<LayerFactory::LayerType>(layerTypeNb);

	return layerTypeInitCopy;
}


LayerType LayerFactory::operator--(
LayerFactory::LayerType& layerType) {
	int layerTypeNb;

	layerTypeNb = static_cast<int>(layerType);
	--layerTypeNb;
	layerType = static_cast<LayerFactory::LayerType>(layerTypeNb);

	return layerType;
}
