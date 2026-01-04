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
		std::cout << "Layer::Layer(): " << 
		(*itLastTexture)->get_upper_left_corner().x << ":" <<
		(*itLastTexture)->get_upper_left_corner().y << std::endl;
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

		std::cout << "Layer::Layer(): " << rockRoad.end()-rockRoad.begin() 
		<< std::endl;
    for (itRockRoad = rockRoad.begin(); 
		itRockRoad != rockRoad.end(); ++itRockRoad) {
				std::cout << "Layer::Layer(): adding texture at: " <<
				(*itRockRoad)->get_upper_left_corner().x << ":" <<
				(*itRockRoad)->get_upper_left_corner().y << std::endl;
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
