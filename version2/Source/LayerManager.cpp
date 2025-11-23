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
	currentLayerType_ = vLayerTypes[0];
}


void LayerManager::add_layer(const LayerFactory::LayerType& layerType)  {
	mLayers_[layerType] = LayerFactory::create_layer(layerType);
}


void LayerManager::operator++(int i) {
	currentLayerType_++;	
}


void LayerManager::operator++() {
	++currentLayerType_;	
}


void LayerManager::operator--(int i) {
	currentLayerType_--;	
}


void LayerManager::operator--(int i) {
	--currentLayerType_;	
}


Texture* LayerManager::get_texture_copy_at_coord(const SDL_Point& coord) {
	mLayers_[currentLayerType_]->get_texture_copy_at_coord(coord);
}


void LayerManager::draw() {
	mLayers_[currentLayerType_]->draw();	
}
