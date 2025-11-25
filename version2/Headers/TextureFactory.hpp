#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H

#include "Texture.hpp"

#include "Oak.hpp"
#include "Pine.hpp"
#include "Hornbeam.hpp"
#include "Poplar.hpp"

#include "Grass.hpp"
#include "Sand.hpp"
#include "Bush.hpp"
#include "Flowers.hpp"
#include "Moos.hpp"
#include "Rock.hpp"
#include "SmallTree.hpp"
#include "TallGrass.hpp"

#include "DeepWater.hpp"
#include "ShallowWater.hpp"
#include "GreenBorder.hpp"
#include "GrayBorder.hpp"

#include "MoosRoad.hpp"
#include "RockRoad.hpp"
#include "SandRoad.hpp"


enum class SimpleTextureEnum {
	Sand,
	Bush,
	Flowers,
	Moos,
	Rock,
	SmallTree,
	TallGrass,
	GreenWhiteGrass,
	GreenWhiteGreenGrass,
	Green,
	White
};


enum class CompositeTextureEnum {
	Oak,
	Pine,
	Hornbeam,
	Poplar
};


enum class DeclinedTextureEnum {
	DeepWater,
	GreenBorder,
	GreyBorder,
	MoosRoad,
	SandRoad,
	ShallowWater,
	RockRoad
};


class TextureFactory {
public:
	static SimpleTexture* create_simple_texture(const SDL_Point&, 
							 				  	const SimpleTextureEnum&);

	static CompositeTexture* 
	create_composite_texture(const SDL_Point& pos, 
						   	 const CompositeTextureEnum& textEnum);

	static SimpleTexture*
	create_grass(const SDL_Point&, const GrassType&);

	static void 
	create_road(const SDL_Point&, 
			   const SDL_Point&,
			   std::vector<DeclinedTexture*>,
			   std::vector<DeclinedTexture*>,
			   const DeclinedTextureEnum&);

	static void
	create_border(const SDL_Point&,
				 const SDL_Point&
				 std::vector<DeclinedTexture*>,
			     std::vector<DeclinedTexture*>,
				 const DeclinedTextureEnum&);

	static void
	create_water(const SDL_Point&,
			    std::vector<DeclinedTexture*>,
			    std::vector<DeclinedTexture*>,
				const DeclinedTextureEnum&);

		

private:
	static DeclinedTexture*
	create_declined_texture(const SDL_Point& pos,
						  const DeclinedTextureEnum& declTextEnum,
						  const DeclinedTextureOrientation& orientation);	
};

#endif