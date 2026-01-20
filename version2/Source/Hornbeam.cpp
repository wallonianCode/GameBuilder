#include "../Headers/Hornbeam.hpp"


Hornbeam::Hornbeam(const SDL_FPoint& initPos) {
	std::vector<SDL_FRect> vSrc, vDest; 
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			vSrc.push_back({(float)2+i*S, (float)(34+j)*S+2, S-3, S-2});
			vDest.push_back({initPos.x + i*TILE_DIM, initPos.y + j*TILE_DIM,
			TILE_DIM, TILE_DIM});
		}
	}

	CompositeTexture(leafGreenTextureFileName, 
									 vSrc.begin(), vSrc.end(),
									 vDest.begin(), vDest.end());
}