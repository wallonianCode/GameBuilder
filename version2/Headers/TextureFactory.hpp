#include "Texture.hpp"
#include "CompositeTexture.hpp"
#include "SimpleTexture.hpp"
#include "DeclinedTexture.hpp"


enum class SimpleTextureEnum {
	Sand,
	Bush,
	Flowers,
	Moos,
	Rock,
	SmallTree,
	TallGrass
};


enum class CompositeTextureEnum {
	Oak,
	Pin,
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
	            const SDL_Point&,
			    std::vector<DeclinedTexture*>,
			    std::vector<DeclinedTexture*>,
				const DeclinedTextureEnum&);

private:
	static DeclinedTexture*
	create_declined_texture(const SDL_Point& pos,
						  const DeclinedTextureEnum& declTextEnum,
						  const DeclinedTextureOrientation& orientation);



	
};
