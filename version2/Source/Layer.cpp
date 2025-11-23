#include "../Headers/Layer.hpp"



Layer::Layer(const int width) : width_(width) {}


Texture* Layer::get_texture_copy_at_coord(const SDL_Point& coord) {
	std::vector<Texture*>::iterator itTextureCopyAtCoord; 

	itTextureCopyAtCoord = 
	std::find_if(vTextures_.begin(), vTextures_.end(), 
							 TextureComparator(coord));
  return itTextureCopyAtCoord->copy();	
}


void Layer::draw() {
	std::vector<Texture*>::iterator itTextures;
	for (itTexture = vTextures_.begin();
			 itTexture != vTextures_.end();
			 ++itTextures) {
		itTextures -> draw();
	}
}
