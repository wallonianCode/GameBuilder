#ifndef ROAD_H
#define ROAD_H

#include "LeafGreenTexture.hpp"


class Road : public LeafGreenTexture {
public:
	Road(const SDL_Point& posOnScreen);	
	void update() override;
	//friend std::istream& operator>>(std::istream& is, Road& road);
private:
	void init_src() = 0; 
	virtual void init_src(const LeafGreenTexture::Side&) = 0;
};

#endif
