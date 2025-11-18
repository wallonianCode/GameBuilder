#include "../Headers/BigTree.hpp"

Oak::Oak(const SDL_Point& initPos) {
	std::vector<SDL_Rect> vSrc, vDest;
	for (int i = 0; i <= 2; ++i) {
		for (int j = 0; j <= 3; ++j) {
			vSrc.push_back((14+i)*S+2, j*S+1, S-3, S-2);
			vDest.push_back({initPos.x + i*TILE_DIM, initPos.y + j*TILE_DIM, 
			TILE_DIM, TILE_DIM});
		}
	}
	CompositeTexture(leafGreenTextureFileName, 
									 vSrc.begin(), vSrc.end(),
									 vDest.begin(), vDest.end());
}


int Oak::get_width() {
	return 3*TILE_WIDTH;
}


int Oak::get_height() {
	return 4*TILE_HEIGHT;
}
