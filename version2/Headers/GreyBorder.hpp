#ifndef GRAY_BORDER_H
#define GRAY_BORDER_H

#include "Border.hpp"

/*
class GreyBorder : public TextureCloneable<Border, GreyBorder> {
public:
	GreyBorder(const SDL_Point&);
	GreyBorder(const SDL_Point&, const Border::Side&);
	GreyBorder(const SDL_Point&, const std::string&);
	void save(std::ostream&) const override;
private:
	void init_src() override;
	void init_src(const Border::Side&) override;

	SDL_Rect arSrcRect[10] = 
	{ {6*S+2, 8*S+2, S-3, S-3}, {7*S+2, 8*S+2, S-3, S-3},
		{8*S+2, 8*S+2, S-3, S-3}, {6*S+2, 9*S+2, S-3, S-3},
		{7*S+2, 9*S+2, S-3, S-3}, {8*S+2, 9*S+2, S-3, S-3},
		{7*S+2, 7*S+2, S-3, S-3}, {8*S+2, 7*S+2, S-3, S-3},
		{8*S+2, 6*S+2, S-3, S-3}, {6*S+2, 2, S-3, S-3} };
	Side side_ = Side(Side::Type::None);
};
*/

class GreyBorder : public TextureCloneable<DeclinedTexture, GreyBorder> {
public:
	GreyBorder(const SDL_Point&, const DeclinedTextureOrientation&);
};


#endif
