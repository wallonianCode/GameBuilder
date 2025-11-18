#ifndef OAK_H
#define OAK_H


#include "CompositeTexture.hpp"

class Oak : public TextureCloneable<CompositeTexture, Oak> {
public:
	Oak (const SDL_Point& initPos);
	static int get_height();
	static int get_width();
};
#endif
