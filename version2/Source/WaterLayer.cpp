#include "../Headers/WaterLayer.hpp"


WaterLayer::WaterLayer(const int width, 
const SDL_FPoint& upperLeftCorner) : Layer(width, upperLeftCorner) {
		const unsigned size = 9;
    std::array<DeclinedTexture*, size> deepWater, shallowWater;
    std::array<DeclinedTexture*, size>::iterator itDeepWater, 
		itShallowWater, itLastTexture;

    TextureFactory::create_water(upperLeftCorner,
                                 deepWater.begin(), deepWater.end(),
                                 DeclinedTextureEnum::DeepWater);
    
   
    itLastTexture = deepWater.end() - 1;

		TextureFactory::create_water({
		upperLeftCorner.x, 
		(*itLastTexture)->get_upper_left_corner().y + 
		(*itLastTexture)->get_height()}, 
		shallowWater.begin(), shallowWater.end(), 
		DeclinedTextureEnum::ShallowWater);
   
	 for (itDeepWater = deepWater.begin(); 
         itDeepWater != deepWater.end(); ++itDeepWater) {
        this->add_texture(*itDeepWater);
    }
 
    for (itShallowWater = shallowWater.begin();
         itShallowWater != shallowWater.end(); ++itShallowWater) {
        this->add_texture(*itShallowWater);
    }
}
