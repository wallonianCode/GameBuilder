#include "../Headers/Poplar.hpp"


Poplar::Poplar(const SDL_FPoint& initPos) {
	std::vector<SDL_FRect> vSrc, vDest; 
	
	for (int j = 0; j < 3; ++j) {
		vSrc.push_back({(float)17*S+1, (float)(13+j)*S+2, S-1, S-3});
		vDest.push_back({initPos.x, initPos.y + j*TILE_DIM, TILE_DIM, TILE_DIM});
	}

	CompositeTexture(leafGreenTextureFileName, 
									 vSrc.begin(), vSrc.end(),
									 vDest.begin(), vDest.end());
}