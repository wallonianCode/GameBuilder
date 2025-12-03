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


static void create_road(const SDL_FPoint& posBegin, 
					    const SDL_FPoint& posEnd,
					    std::vector<DeclinedTexture*>::iterator itRoadBegin,
					    std::vector<DeclinedTexture*>::iterator itRoadEnd,
					    const DeclinedTextureEnum& road) {
	std::vector<DeclinedTextureOrientation> roadOrientations =
	{DeclinedTextureOrientation::East, DeclinedTextureOrientation::West, 
	 DeclinedTextureOrientation::North, DeclinedTextureOrientation::South,
	 DeclinedTextureOrientation::SouthWest, DeclinedTextureOrientation::SouthEast,
	 DeclinedTextureOrientation::NorthWest, DeclinedTextureOrientation::NorthEast,
	 DeclinedTextureOrientation::SouthEastCorner, DeclinedTextureOrientation::SouthWestCorner,
	 DeclinedTextureOrientation::NorthEastCorner, DeclinedTextureOrientation::SouthEastCorner}; //TODO

	SDL_FPoint pos; 
	std::vector<DeclinedTextureOrientation>::iterator itOrientation;
	std::vector<DeclinedTexture*>::iterator itRoad;

	pos = posBegin;
	itRoad = itRoadBegin;
	for (itOrientation = roadOrientations.begin();
		 itOrientation != roadOrientations.end(); ++itOrientation) {
		*itRoad = TextureFactory::create_declined_texture(pos, road, *itOrientation);
		if (pos.x <= posEnd.x - (*itRoad)->get_width()) {
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


static void create_border(const SDL_FPoint& posBegin, 
					   	  const float width,
					   	  std::vector<DeclinedTexture*>::iterator itBorderBegin,
					   	  std::vector<DeclinedTexture*>::iterator itBorderEnd,
					   	  const DeclinedTextureEnum& border) {
	std::vector<DeclinedTextureOrientation> borderOrientations;
	std::vector<DeclinedTextureOrientation>::iterator itBorderOrientations;
	std::vector<DeclinedTexture*>::iterator itBorder;
	SDL_FPoint pos;
	
	borderOrientations =
	{ DeclinedTextureOrientation::SouthWest , DeclinedTextureOrientation::South,
	  DeclinedTextureOrientation::SouthEast, DeclinedTextureOrientation::SouthEastCorner,
	  DeclinedTextureOrientation::East, DeclinedTextureOrientation::NorthEastCorner,
	  DeclinedTextureOrientation::SouthWestCorner, DeclinedTextureOrientation::West };
	
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


static void create_water(const SDL_FPoint& posBegin,
					     std::vector<DeclinedTexture*>::iterator itWaterBegin,
					     std::vector<DeclinedTexture*>::iterator itWaterEnd,
						 const DeclinedTextureEnum& water) {
	std::vector<DeclinedTextureOrientation> waterOrientations;
	std::vector<DeclinedTextureOrientation>::iterator itOrientation;
	std::vector<DeclinedTexture*>::iterator itWater;
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
