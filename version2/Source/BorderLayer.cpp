#include "../Headers/BorderLayer.hpp"


BorderLayer::BorderLayer(const int width, const SDL_Point& upperLeftCorner) : 
Layer(width, upperLeftCorner) {
    SDL_Point pos;
    std::vector<DeclinedTexture*> greyBorders, greenBorders;
    std::vector<DeclinedTexture*>::iterator itBorder;

    pos = upperLeftCorner;

    TextureFactory::create_border(pos, width,
                                  greenBorders.begin(), greenBorders.end(),
                                  DeclinedTextureEnum::GreenBorder);
    itBorder = greenBorders.end()-1;
    pos = {upperLeftCorner.x, itBorder->get_upper_left_corner() + DeclinedTexture::get_height()};

    TextureFactory::create_border(pos, width,
                                  greyBorders.begin(), greyBorders.end(),
                                  DeclinedTextureEnum::GreyBorder);

    this->add_texture(greenBorders);
    this->add_texture(greyBorders);
}