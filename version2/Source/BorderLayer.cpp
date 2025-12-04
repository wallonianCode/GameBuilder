#include "../Headers/BorderLayer.hpp"


BorderLayer::BorderLayer(const int width, const SDL_FPoint& upperLeftCorner) : 
Layer(width, upperLeftCorner) {
    SDL_FPoint pos;
    std::vector<DeclinedTexture*> greyBorders, greenBorders;
    std::vector<DeclinedTexture*>::iterator itBorder;

    pos = upperLeftCorner;

    TextureFactory::create_border(pos, width,
                                  greenBorders.begin(), greenBorders.end(),
                                  DeclinedTextureEnum::GreenBorder);
    itBorder = greenBorders.end()-1;
    pos = {upperLeftCorner.x, (*itBorder)->get_upper_left_corner().y + (*itBorder)->get_height()};

    TextureFactory::create_border(pos, width,
                                  greyBorders.begin(), greyBorders.end(),
                                  DeclinedTextureEnum::GreyBorder);

    for (itBorder = greenBorders.begin(); itBorder != greenBorders.end(); ++itBorder) {
        this->add_texture(*itBorder);
    }

    for (itBorder = greyBorders.begin(); itBorder != greyBorders.end(); ++itBorder) {
        this->add_texture(*itBorder);
    }
 
    
}