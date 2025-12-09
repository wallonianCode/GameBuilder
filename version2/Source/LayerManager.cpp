#include "../Headers/LayerManager.hpp"


LayerManager::LayerManager(const int width, 
const SDL_FPoint& upperLeftCorner) : 
width_(width), upperLeftCorner_(upperLeftCorner) {
	std::vector<LayerFactory::LayerType> vLayerTypes =
	{ LayerFactory::LayerType::Road,
		LayerFactory::LayerType::Tree,
		LayerFactory::LayerType::Soil,
		LayerFactory::LayerType::Water,
		LayerFactory::LayerType::Border
	};

	for (std::vector<LayerFactory::LayerType>::iterator ltIt = vLayerTypes.begin();
		   ltIt != vLayerTypes.end(); ++ltIt) {
		this->add_layer(*ltIt);	
	}
	currentLayerType_ = vLayerTypes[0];
}


void LayerManager::add_layer(const LayerFactory::LayerType& layerType)  {
	mLayers_[layerType] = LayerFactory::create_layer(width_, upperLeftCorner_, layerType);
}


void LayerManager::operator++(int i) {
	currentLayerType_ = 
	LayerFactory::get_next_layer_type(currentLayerType_);
}


void LayerManager::operator++() {
	currentLayerType_ = 
	LayerFactory::get_next_layer_type(currentLayerType_);
}


void LayerManager::operator--(int i) {
	currentLayerType_ = 
	LayerFactory::get_precedent_layer_type(currentLayerType_);	
}


void LayerManager::operator--() {
	currentLayerType_ = 
	LayerFactory::get_precedent_layer_type(currentLayerType_);
}


Texture* LayerManager::get_texture_copy_at_coord(const SDL_FPoint& coord) { 
	return mLayers_[currentLayerType_]->get_texture_copy_at_coord(coord);
}


void LayerManager::draw() {
	mLayers_[currentLayerType_]->draw();	
}
