#include "../Headers/Layer.hpp"



Layer::Layer(const int width, const SDL_Point& upperLeftCorner) : 
width_(width), upperLeftCorner_(upperLeftCorner) {}


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


void Layer::add_texture(Texture* newTexture) {
	//TODO
	// check texture position, if there is not already one there!
}


SDL_Point get_upper_left_corner() const {
	return upperLeftCorner_;
}
