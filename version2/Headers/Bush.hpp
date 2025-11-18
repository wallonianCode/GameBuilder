#ifndef BUSH_HPP
#define BUSH_HPP

#include "SimpleTexture.hpp"


class Bush : public TextureCloneable<SimpleTexture, Bush> {
public:
	Bush(const SDL_Point&);
};

#endif
