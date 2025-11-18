#ifndef TEXTURECREATOR_H
#define TEXTURECREATOR_H

#include "Texture.hpp"
#include "ShallowWater.hpp"
#include "DeepWater.hpp"
#include "SandRoad.hpp"
#include "MoosRoad.hpp"
#include "RockRoad.hpp"
#include "Grass.hpp"
#include "Sand.hpp"
#include "Character.hpp"


class TextureCreator {
public:
	static Texture* create_texture(const std::string&, const std::string&,
	const SDL_Rect&);
};

#endif
