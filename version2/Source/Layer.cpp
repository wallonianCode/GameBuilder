#include "../Headers/Layer.hpp"


Layer::Layer(const int width, const SDL_FPoint& upperLeftCorner) : 
width_(width), upperLeftCorner_(upperLeftCorner) {}


Texture* Layer::get_texture_copy_at_coord(const SDL_FPoint& coord) {
	std::vector<Texture*>::iterator itTextureCopyAtCoord, itTest;
	Texture* textureAtCoord;
	itTextureCopyAtCoord = 
	std::find_if(vTextures_.begin(), vTextures_.end(), 
				[coord](Texture* texture){
				return texture->is_coord_in_texture(coord);});
	textureAtCoord = itTextureCopyAtCoord == vTextures_.end() ?
	nullptr : (*itTextureCopyAtCoord)->clone();	
	return textureAtCoord;
}


void Layer::add_texture(Texture* newTexture) {
	vTextures_.push_back(newTexture);
}


void Layer::draw() {
	std::vector<Texture*>::iterator itTextures;
	for (itTextures = vTextures_.begin();
			 itTextures != vTextures_.end();
			 ++itTextures) {
		(*itTextures) -> draw();
	}
}


SDL_FPoint Layer::get_upper_left_corner() const {
	return upperLeftCorner_;
}
