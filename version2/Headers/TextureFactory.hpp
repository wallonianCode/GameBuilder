#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H

#include "Texture.hpp"

#include "Oak.hpp"
#include "Pin.hpp"
#include "Hornbeam.hpp"
#include "Poplar.hpp"

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
#include "GreyBorder.hpp"

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
	GreenGrass,
	WhiteGrass
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
	static SimpleTexture* create_simple_texture(const SDL_FPoint&, 
							 				  	const SimpleTextureEnum&);

	static CompositeTexture* 
	create_composite_texture(const SDL_FPoint& pos, 
						   	 const CompositeTextureEnum&) ;


	static void 
	create_road(const SDL_FPoint&, 
			    const SDL_FPoint&,
			    std::vector<DeclinedTexture*>::iterator,
			    std::vector<DeclinedTexture*>::iterator,
			    const DeclinedTextureEnum&);

	static void
	create_border(const SDL_FPoint&,
				 const SDL_FPoint&,
				 std::vector<DeclinedTexture*>::iterator,
			     std::vector<DeclinedTexture*>::iterator,
				 const DeclinedTextureEnum&);

	static void
	create_water(const SDL_FPoint&,
			     std::vector<DeclinedTexture*>::iterator,
			     std::vector<DeclinedTexture*>::iterator,
				 const DeclinedTextureEnum&);

	static DeclinedTexture*
	create_declined_texture(const SDL_FPoint& pos,
						    const DeclinedTextureEnum& declTextEnum,
						  	const DeclinedTextureOrientation& orientation);	
};

#endif
