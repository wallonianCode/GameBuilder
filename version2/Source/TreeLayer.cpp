#include "../Headers/TreeLayers.hpp"


TreeLayer::TreeLayer(const int width, const SDL_Point& upperLeftCorner) : 
Layer(width, upperLeftCorner) {
    CompositeTexture* oak, pine, hornbeam, poplar;
    SimpleTexture* smallTree;
    
    oak = TextureFactory::create_composite_texture(this->get_upper_left_corner(),
                                                   CompositeTextureEnum::Oak);
    pine = TextureFactory::create_composite_texture({this->get_upper_left_corner().x + 
                                                     Oak::get_width(),
                                                    this->get_upper_left_corner().y},
                                                    CompositeTextureEnum::Pine);
    hornbeam = TextureFactory::create_composite_texture({this->get_upper_left_corner().x,
                                                         this->get_upper_left_corner().y + 
                                                         Oak::get_height()},
                                                        CompositeTextureEnum::Hornbeam);
    poplar = TextureFactory::create_composite_texture({this->get_upper_left_corner().x +
                                                        Hornbeam::get_width(),
                                                       this->get_upper_left_corner() + 
                                                         Oak::get_height()});
    
    smallTree = TextureFactory::create_simple_texture({this->get_upper_left_corner().x,
                                                       this->get_upper_left_corner().y +
                                                        Oak::get_height() + 
                                                        Hornbeam::get_height()});

    this->add_texture(oak);
    this->add_texture(pine);
    this->add_texture(hornbeam);
    this->add_texture(poplar);
    this->add_texture(smallTree);
}