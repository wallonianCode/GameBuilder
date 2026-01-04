#include "../Headers/DeclinedTexture.hpp"

DeclinedTexture::DeclinedTexture() : SimpleTexture() {}

DeclinedTexture::DeclinedTexture(const SDL_FPoint& pos):
SimpleTexture(pos) {
		std::cout << "DeclinedTexture::DeclinedTexture(pos): " 
		<< pos.x << ":" << pos.y << std::endl;
}
