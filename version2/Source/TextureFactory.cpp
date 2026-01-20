#include "../Headers/TextureFactory.hpp"


SimpleTexture* 
TextureFactory::create_simple_texture(const SDL_FPoint& pos,
									  const SimpleTextureEnum& textureKind) {
	SimpleTexture* newTexture = nullptr;

	switch (textureKind) {
		case SimpleTextureEnum::Sand: {
			newTexture = new Sand(pos);
			break;
		}
		case SimpleTextureEnum::Bush: {
			newTexture = new Bush(pos);
			break;
		}
		case SimpleTextureEnum::Flowers: {
			newTexture = new Flowers(pos);
			break;
		}
		case SimpleTextureEnum::Moos: {
			newTexture = new Moos(pos);
			break;
		}
		case SimpleTextureEnum::Rock: {
			newTexture = new Rock(pos);
			break;
		}
		case SimpleTextureEnum::SmallTree: {
			newTexture = new SmallTree(pos);
			break;
		}
		case SimpleTextureEnum::TallGrass: {
			newTexture = new TallGrass(pos);
			break;
		}
		case SimpleTextureEnum::GreenWhiteGreenGrass: {
			newTexture = new GreenWhiteGreenGrass(pos);
			break;
		}
		case SimpleTextureEnum::GreenWhiteGrass: {
		  newTexture = new GreenWhiteGrass(pos);
			break;
		}
		case SimpleTextureEnum::GreenGrass: {
			newTexture = new GreenGrass(pos);
			break;
		}
		case SimpleTextureEnum::WhiteGrass: {
			newTexture = new WhiteGrass(pos);
			break;
		}
		default:
			break;
	}
	return newTexture;
}


CompositeTexture*
TextureFactory::create_composite_texture(const SDL_FPoint& pos,
									   	 const CompositeTextureEnum& compositeTextureKind) {
	CompositeTexture* newTexture = nullptr;

	switch (compositeTextureKind) {
		case CompositeTextureEnum::Oak:
		{
		   newTexture = new Oak(pos);	
		   break;
		}
		case CompositeTextureEnum::Pine:
		{
			newTexture = new Pin(pos);
			break;
		}
		case CompositeTextureEnum::Hornbeam:
		{
			newTexture = new Hornbeam(pos);
			break;
		}
		case CompositeTextureEnum::Poplar:
		{
			newTexture = new Poplar(pos);
			break;
		}
		default:
			break;
	}	
	return newTexture;
}


void 
TextureFactory::create_road(const SDL_FPoint& posBegin, 
					    	const int width,
					    	std::array<DeclinedTexture*, 12>::iterator itRoadBegin,
					    	std::array<DeclinedTexture*, 12>::iterator itRoadEnd,
					    	const DeclinedTextureEnum& road) {
	std::array<DeclinedTextureOrientation, 12> roadOrientations =
	{DeclinedTextureOrientation::East, DeclinedTextureOrientation::West, 
	 DeclinedTextureOrientation::North, DeclinedTextureOrientation::South,
	 DeclinedTextureOrientation::SouthWest, DeclinedTextureOrientation::SouthEast,
	 DeclinedTextureOrientation::NorthWest, DeclinedTextureOrientation::NorthEast,
	 DeclinedTextureOrientation::SouthEastCorner, DeclinedTextureOrientation::SouthWestCorner,
	 DeclinedTextureOrientation::NorthEastCorner, DeclinedTextureOrientation::SouthEastCorner}; //TODO

	SDL_FPoint pos; 
	std::array<DeclinedTextureOrientation, 12>::iterator itOrientation;
	std::array<DeclinedTexture*, 12>::iterator itRoad;

	pos = posBegin;
	itRoad = itRoadBegin;
	for (itOrientation = roadOrientations.begin();
		 itOrientation != roadOrientations.end(); ++itOrientation) {
		itRoad[0] = TextureFactory::create_declined_texture(pos, road, *itOrientation);
		if (pos.x <= width - (*itRoad)->get_width()) {
			pos.x += (*itRoad)->get_width();
		}
		else {
			pos.x = posBegin.x;
			pos.y += (*itRoad)->get_height();
		}
		++itRoad;
	}
	itRoadEnd = itRoad + 1;	
}


void 
TextureFactory::create_border(const SDL_FPoint& posBegin, 
					   	  	  const int width,
					   	  	  std::array<DeclinedTexture*, 10>::iterator itBorderBegin,
					   	  	  std::array<DeclinedTexture*, 10>::iterator itBorderEnd,
					   	  	  const DeclinedTextureEnum& border) {
	std::array<DeclinedTextureOrientation, 10> borderOrientations;
	std::array<DeclinedTextureOrientation, 10>::iterator itBorderOrientations;
	std::array<DeclinedTexture*, 10>::iterator itBorder;
	SDL_FPoint pos;
	
	borderOrientations =
	{ DeclinedTextureOrientation::SouthWest , DeclinedTextureOrientation::South,
	  DeclinedTextureOrientation::SouthEast, DeclinedTextureOrientation::SouthEastCorner,
	  DeclinedTextureOrientation::East, DeclinedTextureOrientation::NorthEast,
	  DeclinedTextureOrientation::SouthWestCorner, DeclinedTextureOrientation::West,
	  DeclinedTextureOrientation::NorthEastCorner, DeclinedTextureOrientation::Center};
	
	pos = posBegin;
	itBorder = itBorderBegin;

	for (itBorderOrientations = borderOrientations.begin(); 
		 itBorderOrientations != borderOrientations.end(); ++itBorderOrientations) {
		(*itBorder) = TextureFactory::create_declined_texture(pos, border, *itBorderOrientations);
		if (pos.x <= width - (*itBorder)->get_width()) { //TODO create border class with static get_height/get_width methods
			pos.x += (*itBorder)->get_width();
		}
		else {
			pos.y += (*itBorder)->get_height();
			pos.x = posBegin.x;
		}
		++itBorder;
	}
	itBorderEnd = itBorder + 1;					
}


void 
TextureFactory::create_water(const SDL_FPoint& posBegin,
					     	 std::array<DeclinedTexture*, 9>::iterator itWaterBegin,
					     	 std::array<DeclinedTexture*, 9>::iterator itWaterEnd,
						 	 const DeclinedTextureEnum& water) {
	std::array<DeclinedTextureOrientation, 9> waterOrientations;
	std::array<DeclinedTextureOrientation, 9>::iterator itOrientation;
	std::array<DeclinedTexture*, 9>::iterator itWater;
	SDL_FPoint pos;
	int itPos;

	waterOrientations = 
	{ DeclinedTextureOrientation::NorthWest, DeclinedTextureOrientation::North, 
	  DeclinedTextureOrientation::NorthEast, DeclinedTextureOrientation::West,
	  DeclinedTextureOrientation::Center, DeclinedTextureOrientation::East,
	  DeclinedTextureOrientation::SouthWest, DeclinedTextureOrientation::South,
	  DeclinedTextureOrientation::SouthEast };
	itWater = itWaterBegin;
	pos = posBegin;
	itPos = 1;
	for (itOrientation = waterOrientations.begin(); 
		 itOrientation != waterOrientations.end();
		 ++itOrientation) {
		*itWater = TextureFactory::create_declined_texture(pos, water, *itOrientation);

		if (itPos < 3) {
			pos.x += (*itWater)->get_width();
			itPos++;
		}
		else {
			pos.x = posBegin.x;
			pos.y += (*itWater)->get_height();
			itPos = 1;
		}
		++itWater;
	}
	itWaterEnd = itWater + 1;
}




DeclinedTexture*
TextureFactory::create_declined_texture(const SDL_FPoint& pos,
									    const DeclinedTextureEnum& declinedTextureEnum,
									  	const DeclinedTextureOrientation& orientation) {
	DeclinedTexture* newTexture = nullptr;
	switch (declinedTextureEnum) {
		case DeclinedTextureEnum::RockRoad: {
			newTexture = new RockRoad(pos, orientation);
			break;
		}
		case DeclinedTextureEnum::MoosRoad: {
			newTexture = new MoosRoad(pos, orientation);
			break;
		}
		case DeclinedTextureEnum::SandRoad: {
			newTexture = new SandRoad(pos, orientation);
			break;
		}
		case DeclinedTextureEnum::GreenBorder: {
			newTexture = new GreenBorder(pos, orientation);
			break;
		}
		case DeclinedTextureEnum::GreyBorder: {
			newTexture = new GreyBorder(pos, orientation);
			break;
		}
		case DeclinedTextureEnum::DeepWater: {
			newTexture = new DeepWater(pos, orientation);
			break;
		}
		case DeclinedTextureEnum::ShallowWater: {
			newTexture = new ShallowWater(pos, orientation);
			break;
		}
		default:
			break;
	}
	return newTexture;
}
