#include "../Headers/Poplar.hpp"


Poplar::Poplar(const SDL_Point& initPos) {
	std::vector<SDL_Rect> vSrc, vDest; 
	
	for (int j = 0; j < 3; ++j) {
		vSrc.push_back(17*S+1, (13+j)*S+2, S-1, S-3);
		vDest.push_back(initPos.x, initPos.y + j*TILE_DIM, 
										TILE_DIM, TILE_DIM);
	}

	CompositeTexture(leafGreenTextureFileName, 
									 vSrc.begin(), vSrc.end(),
									 vDest.begin(), vDest.end());
}


int Poplar::get_width() {
	return 2*TILE_WIDTH;
}


int Poplar::get_height() {
	return 3*TILE_HEIGHT;
}
