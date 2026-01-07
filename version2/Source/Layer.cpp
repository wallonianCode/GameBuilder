#include "../Headers/Layer.hpp"



Layer::Layer(const int width, const SDL_FPoint& upperLeftCorner) : 
width_(width), upperLeftCorner_(upperLeftCorner) {}


Texture* Layer::get_texture_copy_at_coord(const SDL_FPoint& coord) {
	std::vector<Texture*>::iterator itTextureCopyAtCoord; 
	Texture* textureAtCoord;
	std::cout << "Layer::get_texture_copy_at_coord(const SDL_FPoint& coord): begin " <<
	vTextures_.size() << std::endl;
	std::cout << (vTextures_[1]->get_upper_left_corner().x) << std::endl;
	itTextureCopyAtCoord = 
	std::find_if(vTextures_.begin(), vTextures_.end(), 
				[coord](Texture* texture){
				return texture->get_upper_left_corner().x == coord.x && 
				texture->get_upper_left_corner().y == coord.y;});
	std::cout << "Layer::get_texture_copy_at_coord(const SDL_FPoint& coord): itTextureCopyAtCoord found" << 
	std::endl;
	textureAtCoord = itTextureCopyAtCoord == vTextures_.end() ?
	nullptr : (*itTextureCopyAtCoord)->clone();	
	std::cout << "Layer::get_texture_copy_at_coord(const SDL_FPoint& coord): texture cloned? " << 
	(textureAtCoord == nullptr) << std::endl;
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
