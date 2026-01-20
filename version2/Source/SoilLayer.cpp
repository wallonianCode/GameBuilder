#include "../Headers/SoilLayer.hpp"


SoilLayer::SoilLayer(const int width, const SDL_FPoint& upperLeftCorner) :
Layer(width, upperLeftCorner) {
    int i;
    SDL_FPoint pos, posGrass, posPlant;
    std::array<SimpleTextureEnum, 4> grassTypes, plantTypes;
    
    grassTypes = {SimpleTextureEnum::GreenWhiteGrass, SimpleTextureEnum::GreenWhiteGreenGrass,
                  SimpleTextureEnum::GreenGrass, SimpleTextureEnum::WhiteGrass};
    
    plantTypes = {SimpleTextureEnum::Bush, SimpleTextureEnum::Flowers, 
                  SimpleTextureEnum::Moos, SimpleTextureEnum::TallGrass};
    i = 0;
    pos = upperLeftCorner;
    
    for (i = 0; i <= 3; ++i) {
        posGrass = {upperLeftCorner.x + i*SimpleTexture::get_standard_width(), upperLeftCorner.y};
        posPlant = {upperLeftCorner.x + i*SimpleTexture::get_standard_width(), 
                    upperLeftCorner.y + SimpleTexture::get_standard_height()};
        this->add_texture(TextureFactory::create_simple_texture({posGrass}, grassTypes[i]));
        this->add_texture(TextureFactory::create_simple_texture({posPlant}, plantTypes[i]));
        i++;
    }


    this->add_texture(
        TextureFactory::create_simple_texture({upperLeftCorner.x, 
                                               upperLeftCorner.y + 
                                               2*SimpleTexture::get_standard_height()},
                                               SimpleTextureEnum::Sand));
    this->add_texture(
        TextureFactory::create_simple_texture({
            upperLeftCorner.x + SimpleTexture::get_standard_width(), 
            upperLeftCorner.y + 2*SimpleTexture::get_standard_height()}, SimpleTextureEnum::Rock));   


}