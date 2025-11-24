#include "../Headers/RoadLayer.hpp"


RoadLayer::RoadLayer(const int width) : Layer(width) {
    std::vector<DeclinedTexture*> rockRoad, moosRoad, sandRoad;
    td::vector<DeclinedTexture*>::iterator itLastTexture, itRockRoad, itMoosRoad, itSandRoad;
    SDL_Point upperLeftCorner;
    
    upperLeftCorner = this->get_upper_left_corner();
    TextureFactory::createRoad(upperLeftCorner, 
                               {upperLeftCorner.x + width, upperLeftCorner.y},
                               rockRoad.begin(), rockRoad.end(),
                               DeclinedTextureEnum::RockRoad);

    itLastTexture = rockRoad.end()-1;
    upperLeftCorner = {upperLeftCorner.x,
                       itLastTexture->get_upper_left_corner().y + itLastTexture->get_height()};
    TextureFactory::createRoad(upperLeftCorner,
                               {upperLeftCorner.x + width, upperLeftCorner.y},
                                moosRoad.begin(), moosRoad.end(),
                                DeclinedTextureEnum::moosRoad);

    itLastTexture = moosRoad.end()-1;
    upperLeftCorner = {upperLeftCorner.x,
                       itLastTexture->get_upper_left_corner().y + itLastTexture->get_height()};
    TextureFactory::createRoad(upperLeftCorner,
                               {upperLeftCorner.x + width, upperLeftCorner.y},
                                sandRoad.begin(), sandRoad.end(),
                                DeclinedTextureEnum::SandRoad);


    for (itRockRoad = rockRoad.begin(); itRockRoad != rockRoad.end(); ++itRockRoad) {
        this->add_texture(*itRockRoad);
    }

    for (itMoosRoad = moosRoad.begin(); itMoosRoad != moosRoad.end(); ++itMoosRoad) {
        this->add_texture(*itMoosRoad);
    }

    for (itSandRoad = sandRoad.begin(); itSandRoad != sandRoad.end(); ++itSandRoad) {
        this->add_texture(*itSandRoad);
    }
}