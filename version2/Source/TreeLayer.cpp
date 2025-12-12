#include "../Headers/TreeLayer.hpp"


TreeLayer::TreeLayer(const int width, const SDL_FPoint& upperLeftCorner) : 
Layer(width, upperLeftCorner) {
    std::cout << "TreeLayer::TreeLayer" << std::endl;
    CompositeTexture *oak, *pine, *hornbeam, *poplar;
    SimpleTexture* smallTree;
    
    oak = TextureFactory::create_composite_texture(this->get_upper_left_corner(),
                                                   CompositeTextureEnum::Oak);
    std::cout << "TreeLayer::TreeLayer Oak created" << std::endl;
    std::cout << oak->get_width() << " : " << this->get_upper_left_corner().x << std::endl;
    pine = TextureFactory::create_composite_texture({this->get_upper_left_corner().x + 
                                                     oak->get_width(),
                                                    this->get_upper_left_corner().y},
                                                    CompositeTextureEnum::Pine);
    std::cout << "TreeLayer::TreeLayer Pine created" << std::endl;
    hornbeam = TextureFactory::create_composite_texture({this->get_upper_left_corner().x,
                                                         this->get_upper_left_corner().y + 
                                                         oak->get_height()},
                                                        CompositeTextureEnum::Hornbeam);
    std::cout << "TreeLayer::TreeLayer Hornbeam created" << std::endl;
    poplar = TextureFactory::create_composite_texture({this->get_upper_left_corner().x +
                                                        hornbeam->get_width(),
                                                       this->get_upper_left_corner().y + 
                                                         oak->get_height()},
                                                         CompositeTextureEnum::Poplar);
    
    smallTree = TextureFactory::create_simple_texture({this->get_upper_left_corner().x,
                                                       this->get_upper_left_corner().y +
                                                       oak->get_height() + 
                                                       hornbeam->get_height()},
                                                      SimpleTextureEnum::SmallTree);

    this->add_texture(oak);
    this->add_texture(pine);
    this->add_texture(hornbeam);
    this->add_texture(poplar);
    this->add_texture(smallTree);
    std::cout << "TreeLayer::TreeLayer end" << std::endl;
}