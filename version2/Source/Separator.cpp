#include "../Headers/Separator.hpp"


void Separator::draw() {
	for (std::vector<Texture*>::iterator vTextureIt = vTextures.begin();
			 vTextureIt != vTextures.end(); vTextureIt++) {
		(*vTextureIt)->draw();
	}
}


//nothing to select, and nothing to move 
void Separator::handle_event(SDL_Event& event) {}


bool Separator::is_mouse_in() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	return ((x > xBegin_) && (x < xEnd_));
}


Separator::Separator() {
	int i = 0;
	while(i*TILE_DIM < WINDOW_HEIGHT) {
		Bush *bushLeft = new Bush({xBegin_, i*TILE_DIM}),
				 *bushRight = new Bush({xEnd_ - TILE_DIM, i*TILE_DIM});
		vTextures.push_back(bushLeft);
		vTextures.push_back(bushRight);
		i++;
	}
}
