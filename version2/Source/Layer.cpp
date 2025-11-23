#include "../Headers/Layer.hpp"



Layer::Layer(const int width) : width_(width) {}


Texture* Layer::get_texture_copy_at_coord(const SDL_Point& coord) {
	std::vector<Texture*>::iterator itTextureCopyAtCoord; 

	itTextureCopyAtCoord = 
	std::find_if(vTextures_.begin(), vTextures_.end(), 
							 TextureComparator(coord));
  return itTextureCopyAtCoord->copy();	
}




Texture* get_selected_texture_copy() {
	Texture* selectedTextureCopy = nullptr;
	if (frame_->is_frozen()) {
		selectedTextureCopy = get_texture_at_current_mouse_pos() -> copy();
	}
	else {
		//TODO error code
	}
	return selectedTextureCopy;

}
 */

//TODO TexturePosComparator must take texture size in consideration
/*
SDL_Rect Layer::get_current_texture_rectangle() const {
	//int x, y;
	SDL_Point gridCoord;
	std::vector<Texture*>::iterator itTextureA gridCoord;
	SDL_Rect foundTextureRectangle;

	//SDL_GetMouseState(&x, &y);
 	gridCoord = MapUtils::get_coordinates_at_mouse_pos({x, y});	
	itTextureA gridCoord = std::find(vTextures_.begin(), vTextures_.end(); 
								     TexturePosComparator(gridCoord));
	if (itTextureA gridCoord != vTextures_.end()) {	
		foundTextureRectangle.x = gridCoord.x;
		foundTextureRectangle.y = gridCoord.y;
		foundTextureRectangle.w = itTextureA gridCoord->get_width();
		foundTextureRectangle.h = itTextureA gridCoord->get_height();
	}
	else { // no texture means default dimensions.
		foundTextureRectangle =  gridCoord.x, gridCoord.y, TILE_DIM, TILE_DIM};
	}
	return foundTextureRectangle;
}
 */

Texture* get_texture_at_current_mouse_pos() {

}
