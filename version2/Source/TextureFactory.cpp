#include "../Headers/TextureFactory.cpp"


SimpleTexture* 
TextureFactory::create_simple_texture(const SDL_Point& pos,
									const TextureEnum& textureKind) {
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
TextureFactory::create_composite_texture(const SDL_Point& pos,
									   	 const CompositeTextureEnum& compositeTextureKind) {
	CompositeTexture* newTexture = nullptr;

	switch (compositeTextureKind) {
		case CompositeTextureEnum::Oak:
		{
		   newTexture = new Oak(pos);	
		   break;
		}
		case CompositeTextureEnum::Pin:
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


static void create_road(const SDL_Point& posBegin, 
					    const SDL_Point& posEnd,
					    std::vector<DeclinedTexture*> itRoadBegin,
					    std::vector<DeclinedTexture*> itRoadEnd,
					    const DeclinedTextureEnum& road) {
	std::vector<DeclinedTextureOrientation> roadOrientations =
	{DeclinedTextureOrientation::East, DeclinedTextureOrientation::West, 
	 DeclinedTextureOrientation::North, DeclinedTextureOrientation::South,
	 DeclinedTextureOrientation::SouthWest, DeclinedTextureOrientation::SouthEast,
	 DeclinedTextureOrientation::NorthWest, DeclinedTextureOrientation::NorthEast,
	 DeclinedTextureOrientation::SouthEastCorner, DeclinedTextureOrientation::SouthWestCorner,
	 DeclinedTextureOrientation::NorthEastCorner, DeclinedTextureOrientation::SouthEastCorner}; //TODO

	SDL_Point pos; 
	std::vector<DeclinedTextureOrientation>::iterator itOrientation;
	std::vector<DeclinedTexture*>::iterator itRoad;

	pos = posBegin;
	itRoad = itRoadBegin;
	for (itOrientation = roadOrientations.begin();
		 itOrientation != roadOrientations.end(); ++itOrientation) {
		*itRoad = TextureFactory::create_declined_texture(pos, road, *itOrientation);
		if (pos.x <= posEnd.x - DeclinedTexture::get_width()) {
			pos.x += DeclinedTexture::get_width();
		}
		else {
			pos.x = posBegin.x;
			pos.y += DeclinedTexture::get_height();
		}
		++itRoad;
	}
	itRoadEnd = itRoad + 1;					
}


static void create_border(const SDL_Point& posBegin, 
					   	  const int width,
					   	  std::vector<DeclinedTexture*> itBorderBegin,
					   	  std::vector<DeclinedTexture*> itBorderEnd,
					   	  const DeclinedTextureEnum& border) {
	std::vector<DeclinedTextureOrientation> borderOrientations;
	std::vector<DeclinedTextureOrientation>::iterator itBorderOrientations;
	std::vector<DeclinedTexture*> itBorder;
	SDL_Point pos;
	
	borderOrientations =
	{ DeclinedTextureOrientation::SouthWest , DeclinedTextureOrientation::South,
	  DeclinedTextureOrientation::SouthEast, DeclinedTextureOrientation::SouthEastCorner,
	  DeclinedTextureOrientation::East, DeclinedTextureOrientation::NorthEastCorner,
	  DeclinedTextureOrientation::SouthWestCorner, DeclinedTextureOrientation::West };
	
	pos = posBegin;
	itBorder = itBorderBegin;

	for (itOrientation = borderOrientations.begin(); 
		 itOrientation = borderOrientations.end(); ++itOrientation) {
		itBorder = TextureFactory::create_declined_texture(pos, border, *itOrientation);
		if (pos >= width - DeclinedTexture::get_width()) { //TODO create border class with static get_height/get_width methods
			pos.x += DeclinedTexture::get_width();
		}
		else {
			pos.y += DeclinedTexture::get_height();
			pos.x = posBegin.x;
		}
		++itBorder;
	}
	itBorderEnd = itBorder + 1;					
}


static void create_water(const SDL_Point& posBegin,
					     std::vector<DeclinedTexture*> itWaterBegin,
					     std::vector<DeclinedTexture*> itWaterEnd,
						 const DeclinedTextureEnum& water) {
	std::vector<DeclinedTextureOrientation> waterOrientations;
	std::vector<DeclinedTextureOrientation>::iterator itOrientation;
	std::vector<DeclinedTexture*> itWater;
	SDL_Point pos;
	int itPos;

	waterOrientations = 
	{ DeclinedTextureOrientation::NorthWest, DeclinedTextureOrientation::North, 
	  DeclinedTextureOrientation::NorthEast, DeclinedTextureOrientation::West,
	  DeclinedTextureOrientation::Center, DeclinedTextureOrientation::East,
	  DeclinedTextureOrientation::SouthWest, DeclinedTextureEnum::South,
	  DeclinedTextureOrientation::SouthEast };
	itWater = itWaterBegin;
	pos = posBegin;
	itPos = 1;
	for (itOrientation = waterOrientations.begin(), 
		 itOrientation != waterOrientations.end();
		 ++itOrientation) {
		*itWater = TextureFactory::create_declined_texture(pos, water, *itOrientation);

		if (itPos < 3) {
			pos.x += DeclinedTexture::get_width();
			itPos++;
		}
		else {
			pos.x = posBegin.x;
			pos.y += DeclinedTexture::get_height();
			itPos = 1;
		}
		++itWater;
	}
	itWaterEnd = itWater + 1;
}




DeclinedTexture*
TextureFactory::create_declined_texture(const SDL_Point& pos,
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
