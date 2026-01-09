#include "../Headers/DeclinedTexture.hpp"

DeclinedTexture::DeclinedTexture() : SimpleTexture() {
}

DeclinedTexture::DeclinedTexture(const SDL_FPoint& pos):
SimpleTexture(pos) {
	std::cout << "DeclinedTexture::DeclinedTexture(pos)" << std::endl;
		this->set_upper_left_corner(pos);
		//TODO call to base class constructor with param is ignored by
		// CRTP -> re-read this pattern
}
