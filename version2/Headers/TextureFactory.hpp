#include "Texture.hpp"
#include "CompositeTexture.hpp"
#include "SimpleTexture.hpp"
#include "DeclinedTexture.hpp"
//TODO complete the blueprint of the class

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

//TODO develop the declined texture types based on the blueprint
//     necessary in this class. With an orientation static struct.

class TextureFactory {
public:
	static SimpleTexture* createSimpleTexture(const SDL_Point&, 
							 														  const SimpleTextureEnum&);

	static CompositeTexture* 
	createCompositeTexture(const SDL_Point& pos, 
												 const CompositeTextureEnum& textEnum);


	static DeclinedTexture*
	createDeclinedTexture(const SDL_Point& pos,
												const DeclinedTextureEnum& declTextEnum,
												const Orientation& orientation);
};
