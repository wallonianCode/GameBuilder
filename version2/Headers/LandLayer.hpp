#ifndef LANDLAYER_H
#define LANDLAYER_H


#include "Layer.hpp"

class LandLayer : public Layer {
public:
	LandLayer(const int& width);
	SDL_Point adjust_texture_coordinates(const SDL_Point& coord);
private:
	void init();	
};

#endif
