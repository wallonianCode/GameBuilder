#ifndef MULTITEXTURE_H
#define MULTITEXTURE_H

#include "LeafGreenTexture.hpp"


class MultiTexture : public LeafGreenTexture {
public:
	MultiTexture(const SDL_Point&);
	MultiTexture(const SDL_Point&, const LeafGreenTexture::Side&);
	MultiTexture(const SDL_Point&, const std::string&);
	void update() override;
	virtual SDL_Rect get_src_rect(const Side& side);
	//void save(std::ostream&) const override;
private:
	void init_src();
	void init_src(const LeafGreenTexture::Side&);

	SDL_Rect arSrcRect[8] = 
	{ {S+2, 6*S+2, S-3, S-3}, {S+2, 6*S+2, S-3, S-3},
		{2*S+2, 6*S+2, S-3, S-3}, {4*S+2, 6*S+2, S-3, S-3},
		{3*S+2, 7*S+2, S-3, S-3}, {4*S+2, 7*S+2, S-3, S-3},
		{S+2, 7*S+2, S-3, S-3}, {2*S+2, 7*S+2, S-3, S-3} };
	Side side_ = Side(Side::Type::None);
};


#endif
