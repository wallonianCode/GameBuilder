#ifndef  HORNBEAM_H
#define  HORNBEAM_H

#include "CompositeTexture.hpp"

class Hornbeam : public TextureCloneable<CompositeTexture, Hornbeam> {
public:
	Hornbeam(std::vector<SDL_FRect>::iterator itSrcBegin,
			 std::vector<SDL_FRect>::iterator itSrcEnd,
			 std::vector<SDL_FRect>::iterator itDestBegin,
			 std::vector<SDL_FRect> ::iterator itDestEnd);
	static float get_width();
	static float get_height();
};

#endif
