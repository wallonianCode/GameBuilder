#include "../Headers/CompositeTextureLayer.hpp"


CompositeTextureLayer::CompositeTextureLayer(const int& width) : 
Layer(width) {
	vTextures_.push_back(new Oak(0, 0));
	vTextures_.push_back(new Pin(Oak::get_width(), 0));
	vTextures_.push_back(new Hornbeam(0, Oak::get_height()));
	vTextures_.push_back(new Poplar(Hornbeam::get_width(), 
																	Oak::get_height()));
}


void CompositeTextureLayer::handle_event(SDL_Event&) {
	//TODO
}


void CompositeTextureLayer::get_texture_at_mouse_pos() {

}
