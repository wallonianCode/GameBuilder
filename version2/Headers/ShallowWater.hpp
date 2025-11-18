#ifndef SHALLOWWATER_H
#define SHALLOWWATER_H

#include "Water.hpp"


class ShallowWater : public TextureCloneable<Water, ShallowWater> {
public:
	void save(std::ostream&);

	ShallowWater(const SDL_Point& posOnScreen);
	ShallowWater(const SDL_Point& posOnScreen, 
	const LeafGreenTexture::Side&);
	ShallowWater(const SDL_Point& posOnScreen,
	const std::string& subType);
private:
	std::array<SDL_Rect, 8> rectAr = 
	{{ {11*S+2, 1, S-3, S-3}, {10*S+2, S+2, S-3, S-3}, 
	{10*S+2, S+2, S-3, S-3}, {11*S+2, 2*S+2, S-3, S-2},
	{10*S+1, 1, S-3, S-3}, {12*S+2, 1, S-2, S-3},
	{10*S+1, 2*S+2, S-3, S-2}, {12*S+2, 2*S+2, S-2, S-2} }};

	void init_src() override;
	void init_src(const LeafGreenTexture::Side&) override;
};

#endif
