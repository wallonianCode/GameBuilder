#include "../Headers/WaterLayer.hpp"


WaterLayer::WaterLayer(const int width, const SDL_Point& upperLeftCorner) :
Layer(width, upperLeftCorner) {
    std::vector<DeclinedTexture*> deepWater, shallowWater;
    std::vector<DeclinedTexture*>::iterator itDeepWater, itShallowWater, itLastTexture;


    TextureFactory::create_water(upperLeftCorner,
                                 deepWater.begin(), deepWater.end(),
                                 DeclinedTextureEnum::DeepWater);
    
    for (itDeepWater = deepWater.begin(); 
         itDeepWater = deepWater.end(); ++itDeepWater) {
        this->add_texture(*itDeepWater);
    }

    itLastTexture = deepWater.end() - 1;
    TextureFactory::create_water({upperLeftCorner.x, 
                                  itLastTexture->get_upper_left_corner().y + DeclinedTexture::get_height()},
                                  shallowWater.begin(), shallowWater.end(),
                                  DeclinedTextureEnum::ShallowWater);
    
    for (itShallowWater = shallowWater.begin();
         itShallowWater = shallowWater.end(); ++itShallowWater) {
        this->add_texture(*itShallowWater);
    }
}