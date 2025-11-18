#ifndef WATER_H
#define WATER_H

#include "LeafGreenTexture.hpp"


class Water : public LeafGreenTexture {
public:
	Water(const SDL_Point&);
	Water(const SDL_Point&, const LeafGreenTexture::Side&);
	void update() override;

private:
	virtual void init_src() = 0; 
	virtual void init_src(const LeafGreenTexture::Side&) = 0;
};

#endif
