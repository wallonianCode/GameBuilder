#ifndef TEXTUREPOSITIONCOMPARATOR_H
#define TEXTUREPOSITIONCOMPARATOR_H

#include "Texture.hpp"

class TexturePositionComparator {
public:
	TexturePositionComparator(const SDL_Point&);
	bool operator()(const Texture&);
	bool operator()(Texture*);
private:
	SDL_Point posOnScreen_;
};


#endif
