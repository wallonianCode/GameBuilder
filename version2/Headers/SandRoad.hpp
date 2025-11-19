#ifndef SANDROAD_H
#define SANDROAD_H

#include "Road.hpp"

/*
class SandRoad : public TextureCloneable<Road, SandRoad> {
public:
	SandRoad(const SDL_Point&);
	SandRoad(const SDL_Point&, const LeafGreenTexture::Side&);
	SandRoad(const SDL_Point&, const std::string&);
private:
	void init_src() override;
	void init_src(const LeafGreenTexture::Side&) override;

	SDL_Rect arSrcRect[8] = 
	{ {S+2, 2, S-3, S-3}, {2*S+2, 2, S-3, S-3}, 
		{3*S+2, 2, S-3, S-3}, {4*S+2, 2, S-3, S-3},
		{3*S+2, S+2, S-3, S-3}, {4*S+2, S+2, S-3, S-3},
		{S+2, S+2, S-3, S-3}, {2*S+2, S+2, S-3, S-3} };
	LeafGreenTexture::Side side_;
};
*/

class SandRoad : public TextureCloneable<DeclinedTexture, SandRoad> {
public:
	SandRoad(const SDL_Point&, const DeclinedTextureOrientation&);
};
#endif
