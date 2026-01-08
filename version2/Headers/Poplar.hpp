#ifndef  POPLAR_H
#define  POPLAR_H

#include "CompositeTexture.hpp"

class Poplar : public TextureCloneable<CompositeTexture, Poplar> {
public:
	Poplar(std::vector<SDL_FRect>::iterator itSrcBegin,
		   std::vector<SDL_FRect>::iterator itSrcEnd,
		   std::vector<SDL_FRect>::iterator itDestBegin,
		   std::vector<SDL_FRect> ::iterator itDestEnd);
	
	float get_width() const override;
	float get_height() const override;
};

#endif
