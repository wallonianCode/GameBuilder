#include "../Headers/Hornbeam.hpp"


Hornbeam::Hornbeam(std::vector<SDL_FRect>::iterator itSrcBegin,
					 std::vector<SDL_FRect>::iterator itSrcEnd,
					 std::vector<SDL_FRect>::iterator itDestBegin,
					 std::vector<SDL_FRect> ::iterator itDestEnd) : 
					 CompositeTexture(leafGreenTextureFileName, itSrcBegin, 
						itSrcEnd, itDestBegin, itDestEnd) {}

float Hornbeam::get_width() const {
	return 3*TILE_DIM;
}

float Hornbeam::get_height() const {
	return 4*TILE_DIM;
}

