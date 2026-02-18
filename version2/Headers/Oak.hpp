#ifndef OAK_H
#define OAK_H


#include "CompositeTexture.hpp"

class Oak : public TextureCloneable<CompositeTexture, Oak> {
public:
	Oak (std::vector<SDL_FRect>::iterator itSrcBegin,
		 std::vector<SDL_FRect>::iterator itSrcEnd,
		 std::vector<SDL_FRect>::iterator itDestBegin,
		 std::vector<SDL_FRect> ::iterator itDestEnd);

	static float get_width();
	static float get_height();
};
#endif
