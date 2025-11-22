#include "../Headers/LayerManager.hpp"


LayerManager::LayerManager(const int width) : width_(width) {
	std::vector<LayerFactory::LayerType> vLayerTypes =
	{ LayerFactory::LayerType::Roads,
		LayerFactory::LayerType::Trees,
		LayerFactory::LayerType::Soil,
		LayerFactory::LayerType::Buildings };

	for (std::vector<LayerFactory::LayerType> ltIt = vLayerType.begin();
		   ltIt != vLayerTypes.end(); ++ltIt) {
		this->add_layer(*ltIt);	
	}
	currentLayer_ = mLayer_[LayerFactory::LayerType::Soil];
}


void LayerManager::add_layer(const LayerFactory::LayerType& layerType)  {
    switch (LayerType) {
        case LayerFactory::LayerType::Roads: {
            mLayer_[layerType] = new RoadLayer(width_);
            break;
        }
        case LayerFactory::LayerType::Trees: {
            mLayer_[layerType] = new TreeLayer(width_);
            break;
        }
        case LayerFactory::LayerType::Soil: {
            mLayer_[layerType] = new SoilLayer(width_);
            break;
        }
        case LayerFactory::LayerType::Buildings: {
            mLayer_[layerType] = new BuildingLayer(width_);
            break;
        }
        default:
            break;
    }
}


void LayerManager::operator++(int i) {
	int layerNb;

	layerNb = static_cast<int>(currentLayerType_);
	layerNb++;
	
}
