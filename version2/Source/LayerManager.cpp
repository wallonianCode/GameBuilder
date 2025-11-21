#include "../Headers/LayerManager.hpp"


LayerManager::LayerManager(const int width) : width_(width) {}


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