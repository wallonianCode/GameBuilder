#include "../Headers/Poplar.hpp"


Poplar::Poplar(std::vector<SDL_FRect>::iterator itSrcBegin,
		 	   std::vector<SDL_FRect>::iterator itSrcEnd,
		 	   std::vector<SDL_FRect>::iterator itDestBegin,
		 	   std::vector<SDL_FRect> ::iterator itDestEnd) : 
			   CompositeTexture(leafGreenTextureFileName, itSrcBegin, 
				itSrcEnd, itDestBegin, itDestEnd) {}

