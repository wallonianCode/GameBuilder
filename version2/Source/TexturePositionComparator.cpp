#include "../Headers/TexturePositionComparator.hpp"


TexturePositionComparator::TexturePositionComparator(const SDL_Point& pos) : 
posOnScreen_(pos) {}


bool TexturePositionComparator::operator()(const Texture& texture) {
	const SDL_Point textureUpperLeftCorner = texture.get_upper_left_corner();
	return (textureUpperLeftCorner.x == posOnScreen_.x &&
			textureUpperLeftCorner.y == posOnScreen_.y);
}


bool TexturePositionComparator::operator()(Texture* texture) {
	const SDL_Point textureUpperLeftCorner = texture->get_upper_left_corner();
	return (textureUpperLeftCorner.x == posOnScreen_.x &&
			textureUpperLeftCorner.y == posOnScreen_.y);
}