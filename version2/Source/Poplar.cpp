#include "../Headers/Poplar.hpp"


Poplar::Poplar(std::vector<SDL_FRect>::iterator itSrcBegin,
		 	   std::vector<SDL_FRect>::iterator itSrcEnd,
		 	   std::vector<SDL_FRect>::iterator itDestBegin,
		 	   std::vector<SDL_FRect> ::iterator itDestEnd) : 
			   CompositeTexture(leafGreenTextureFileName, itSrcBegin, 
				itSrcEnd, itDestBegin, itDestEnd) {}


float Poplar::get_width() const {
	return TILE_DIM;
}


float Poplar::get_height() const {
	return 3*TILE_DIM;
}