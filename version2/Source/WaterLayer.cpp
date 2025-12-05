#include "../Headers/WaterLayer.hpp"


WaterLayer::WaterLayer(const int width, const SDL_FPoint& upperLeftCorner) :
Layer(width, upperLeftCorner) {
    std::array<DeclinedTexture*, 9> deepWater, shallowWater;
    std::array<DeclinedTexture*, 9>::iterator itDeepWater, itShallowWater, itLastTexture;


    TextureFactory::create_water(upperLeftCorner,
                                 deepWater.begin(), deepWater.end(),
                                 DeclinedTextureEnum::DeepWater);
    
    for (itDeepWater = deepWater.begin(); 
         itDeepWater != deepWater.end(); ++itDeepWater) {
        this->add_texture(*itDeepWater);
    }

    itLastTexture = deepWater.end() - 1;
    TextureFactory::create_water({upperLeftCorner.x, 
                                  (*itLastTexture)->get_upper_left_corner().y + (*itLastTexture)->get_height()},
                                  shallowWater.begin(), shallowWater.end(),
                                  DeclinedTextureEnum::ShallowWater);
    
    for (itShallowWater = shallowWater.begin();
         itShallowWater != shallowWater.end(); ++itShallowWater) {
        this->add_texture(*itShallowWater);
    }
}