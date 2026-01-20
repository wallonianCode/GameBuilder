#include "../Headers/LayerFactory.hpp"


Layer* LayerFactory::create_layer(const int width,
						   const SDL_FPoint& upperLeftCorner,
						   const LayerFactory::LayerType& layerType) {
	Layer* newLayer;
	newLayer = nullptr;
	switch (layerType) {
			case LayerFactory::LayerType::Road: {
				
				newLayer = new RoadLayer(width, upperLeftCorner);
				break;
			}
			case LayerFactory::LayerType::Tree: {
				newLayer = new TreeLayer(width, upperLeftCorner);
				break;
			}
			case LayerFactory::LayerType::Soil: {
				newLayer = new SoilLayer(width, upperLeftCorner);
				break;
			}
			case LayerFactory::LayerType::Buildings: {
				newLayer = new BuildingLayer(width, upperLeftCorner);
				break;
			}
			case LayerFactory::LayerType::Water: {
				newLayer = new WaterLayer(width, upperLeftCorner);
				break;
			}
			case LayerFactory::LayerType::Border: {
				newLayer = new BorderLayer(width, upperLeftCorner);
				break;
			}
			default: {
				throw 
				std::runtime_error("Layer type not recognized");
				break;
			}
    }
	return newLayer;
}

LayerFactory::LayerType LayerFactory::get_next_layer_type(const LayerFactory::LayerType& layerType) {
	int nextLayerTypeNb;
	LayerFactory::LayerType newLayerType;

	if (layerType == LayerFactory::LayerType::Border) {
		newLayerType = LayerFactory::LayerType::Road;
	}
	else {
		nextLayerTypeNb = static_cast<int>(layerType) + 1;
		newLayerType = static_cast<LayerFactory::LayerType>(nextLayerTypeNb);
	}
	return newLayerType;
	
}


LayerFactory::LayerType LayerFactory::get_precedent_layer_type(const LayerFactory::LayerType& layerType) {
	int precLayerTypeNb;
	LayerFactory::LayerType newLayerType;

	if (layerType == LayerFactory::LayerType::Road) {
		newLayerType = LayerFactory::LayerType::Border;
	}
	else {
		precLayerTypeNb = static_cast<int>(layerType) - 1;
		newLayerType = static_cast<LayerFactory::LayerType>(precLayerTypeNb);
	}
		return newLayerType;
}
