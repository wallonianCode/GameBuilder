#include "../Headers/RoadLayer.hpp"


RoadLayer::RoadLayer(const int width, const SDL_FPoint& upperLeftCorner) : 
Layer(width, upperLeftCorner) {
    std::array<DeclinedTexture*, 12> rockRoad, moosRoad, sandRoad;
    std::array<DeclinedTexture*, 12>::iterator itLastTexture, itRockRoad,
		itMoosRoad, itSandRoad; 
		SDL_FPoint upperLeftCornerFromCurrentRoad;
    
    upperLeftCornerFromCurrentRoad = this->get_upper_left_corner();
    TextureFactory::create_road(upperLeftCornerFromCurrentRoad, 
                                upperLeftCornerFromCurrentRoad.x + width, 
                                rockRoad.begin(), rockRoad.end(),
                                DeclinedTextureEnum::RockRoad);

    itLastTexture = rockRoad.end()-1;
    upperLeftCornerFromCurrentRoad = 
		{upperLeftCornerFromCurrentRoad.x,
     (*itLastTexture)->get_upper_left_corner().y + 
		 (*itLastTexture)->get_height()};
    TextureFactory::create_road(upperLeftCornerFromCurrentRoad,
                                upperLeftCornerFromCurrentRoad.x + width, 
                                moosRoad.begin(), moosRoad.end(),
                                DeclinedTextureEnum::MoosRoad);

    itLastTexture = moosRoad.end()-1;
    upperLeftCornerFromCurrentRoad = 
    {upperLeftCornerFromCurrentRoad.x,
    (*itLastTexture)->get_upper_left_corner().y + 
		(*itLastTexture)->get_height()};
    TextureFactory::create_road(upperLeftCornerFromCurrentRoad,
                                upperLeftCornerFromCurrentRoad.x + width, 
                                sandRoad.begin(), sandRoad.end(),
                                DeclinedTextureEnum::SandRoad);

    for (itRockRoad = rockRoad.begin(); 
		itRockRoad != rockRoad.end(); ++itRockRoad) {
        this->add_texture(*itRockRoad);
    }

    for (itMoosRoad = moosRoad.begin(); 
		itMoosRoad != moosRoad.end(); ++itMoosRoad) {
        this->add_texture(*itMoosRoad);
    }

    for (itSandRoad = sandRoad.begin(); 
		itSandRoad != sandRoad.end(); ++itSandRoad) {
        this->add_texture(*itSandRoad);
    }        
}
