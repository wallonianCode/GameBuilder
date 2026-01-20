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



Oak* 
TextureFactory::create_oak(const SDL_FPoint& pos) {
	std::vector<SDL_FRect> vSrc, vDest;
	for (int i = 0; i <= 2; ++i) {
		for (int j = 0; j <= 3; ++j) {
			vSrc.push_back({(float)(14+i)*S+2, (float)j*S+1, S-3, S-2});
			vDest.push_back({pos.x + i*TILE_DIM, pos.y + j*TILE_DIM, 
					TILE_DIM, TILE_DIM});
		}
	}
	return new Oak(vSrc.begin(), vSrc.end(),
			vDest.begin(), vDest.end());
}


Pin*
TextureFactory::create_pin(const SDL_FPoint& pos) {
	std::vector<SDL_FRect> vSrc, vDest;  

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			vSrc.push_back({(float)(14+i)*S+2, (float)(17+j)*S, S-3, S-2});
			vDest.push_back({pos.x + i*TILE_DIM, pos.y + j*TILE_DIM, 
					TILE_DIM, TILE_DIM});
		}
	}

	return new Pin(vSrc.begin(), vSrc.end(),
			vDest.begin(), vDest.end());
}


Hornbeam*
TextureFactory::create_hornbeam(const SDL_FPoint& pos) {
	std::vector<SDL_FRect> vSrc, vDest; 
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			vSrc.push_back({(float)2+i*S, (float)(34+j)*S+2, S-3, S-2});
			vDest.push_back({pos.x + i*TILE_DIM, pos.y + j*TILE_DIM,
					TILE_DIM, TILE_DIM});
		}
	}

	return new Hornbeam(vSrc.begin(), vSrc.end(),
			vDest.begin(), vDest.end());
}


Poplar*
TextureFactory::create_poplar(const SDL_FPoint& pos) {
	std::vector<SDL_FRect> vSrc, vDest; 

	for (int j = 0; j < 3; ++j) {
		vSrc.push_back({(float)17*S+1, (float)(13+j)*S+2, S-1, S-3});
		vDest.push_back({pos.x, pos.y + j*TILE_DIM, TILE_DIM, TILE_DIM});
	}

	return new Poplar(vSrc.begin(), vSrc.end(),
			vDest.begin(), vDest.end());
}



//TODO the declined textures creation always ever call the 
//     default constructor of SimpleTexture(). Not the composite 
//	   ones. Why?
void 
TextureFactory::create_road(const SDL_FPoint& posBegin, 
		const int width,
		std::array<DeclinedTexture*, 12>::iterator itRoadBegin,
		std::array<DeclinedTexture*, 12>::iterator itRoadEnd,
		const DeclinedTextureEnum& road) {
	std::array<DeclinedTextureOrientation, 12> roadOrientations =
	{DeclinedTextureOrientation::East, DeclinedTextureOrientation::West, 
		DeclinedTextureOrientation::North, DeclinedTextureOrientation::South,
		DeclinedTextureOrientation::SouthWest, 
		DeclinedTextureOrientation::SouthEast,
		DeclinedTextureOrientation::NorthWest, 
		DeclinedTextureOrientation::NorthEast,
		DeclinedTextureOrientation::SouthEastCorner, 
		DeclinedTextureOrientation::SouthWestCorner,
		DeclinedTextureOrientation::NorthEastCorner, 
		DeclinedTextureOrientation::SouthEastCorner}; 

	SDL_FPoint pos; 
	std::array<DeclinedTextureOrientation, 12>::iterator itOrientation;
	std::array<DeclinedTexture*, 12>::iterator itRoad;

	pos = posBegin;
	itRoad = itRoadBegin;
	for (itOrientation = roadOrientations.begin();
			itOrientation != roadOrientations.end(); ++itOrientation) {
		*itRoad = 
			TextureFactory::create_declined_texture(pos, road, *itOrientation);
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
	std::array<DeclinedTextureOrientation, 10>::iterator 
		itBorderOrientations;
	std::array<DeclinedTexture*, 10>::iterator itBorder;
	SDL_FPoint pos;

	borderOrientations =
	{ DeclinedTextureOrientation::SouthWest , 
		DeclinedTextureOrientation::South,
		DeclinedTextureOrientation::SouthEast, 
		DeclinedTextureOrientation::SouthEastCorner,
		DeclinedTextureOrientation::East, 
		DeclinedTextureOrientation::NorthEast,
		DeclinedTextureOrientation::SouthWestCorner, 
		DeclinedTextureOrientation::West,
		DeclinedTextureOrientation::NorthEastCorner, 
		DeclinedTextureOrientation::Center};

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
	{ DeclinedTextureOrientation::NorthWest, 
		DeclinedTextureOrientation::North, 
		DeclinedTextureOrientation::NorthEast, 
		DeclinedTextureOrientation::West,
		DeclinedTextureOrientation::Center, 
		DeclinedTextureOrientation::East,
		DeclinedTextureOrientation::SouthWest, 
		DeclinedTextureOrientation::South,
		DeclinedTextureOrientation::SouthEast };
	itWater = itWaterBegin;
	pos = posBegin;
	itPos = 1;

	for (itOrientation = waterOrientations.begin(); 
			itOrientation != waterOrientations.end();
			++itOrientation) {
		*itWater = 
			TextureFactory::create_declined_texture(pos, water, *itOrientation);

		if (itPos < 3) {
			pos.x += (*itWater)->get_width();
			itPos++;
		}
		else { //itPos == 3
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
