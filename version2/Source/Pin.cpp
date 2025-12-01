#include "../Headers/Pin.hpp"


Pin::Pin(const SDL_FPoint& initPos) {
	std::vector<SDL_Rect> vSrc, vDest;  

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			vSrc.push_back((14+i)*S+2, (15+j)*S, S-3, S-3);
			vDest.push_back(initPos.x + i*TILE_DIM, initPos.y + j*TILE_DIM,
											TILE_DIM, TILE_DIM);
		}
	}
	
	CompositeTexture(leafGreenTextureFileName, 
					 vSrc.begin(), vSrc.end(),
					 vDest.begin(), vDest.end());
}