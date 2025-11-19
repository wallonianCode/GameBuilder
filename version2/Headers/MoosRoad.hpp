#ifndef MOOSROAD_H
#define MOOSROAD_H


#include "Road.hpp"

/*
class MoosRoad : public TextureCloneable<Road, MoosRoad> {
public:
	MoosRoad(const SDL_Point&);
	MoosRoad(const SDL_Point&, const LeafGreenTexture::Side&);
	MoosRoad(const SDL_Point&, const std::string&);
private:
	void init_src() override;
	void init_src(const LeafGreenTexture::Side&) override;

	SDL_Rect arSrcRect[8] = 
	{ {3*S+2, 3*S+2, S-3, S-3}, {S+2, 3*S+2, S-3, S-3},
		{2*S+2, 3*S+2, S-3, S-3}, {4*S+2, 3*S+2, S-3, S-3},
		{3*S+2, 4*S+2, S-3, S-3}, {4*S+2, 4*S+2, S-3, S-3},
		{S+2, 4*S+2, S-3, S-3}, {2*S+2, 4*S+2, S-3, S-3} };
	Side side_ = Side(Side::Type::None);
};
*/

/*{North, West, East, South,
		NorthWest, NorthEast, SouthWest, SouthEast, None};*/

class MoosRoad : public TextureCloneable<DeclinedTexture, MoosRoad> {
public:
	MoosRoad(const SDL_Point&,
			 const DeclinedTextureOrientation& orientation);
};
#endif
