#ifndef GRASS_H
#define GRASS_H

#include <string>
#include <array>
#include <algorithm>
#include "SimpleTexture.hpp"


enum class GrassType {
	GreenWhite,
	GreenWhiteGreen,
	Green,
	White
};


class Grass : public TextureCloneable<SimpleTexture, Grass> {
public:
	Grass(const SDL_Point&, const GrassType&);
};

#endif
