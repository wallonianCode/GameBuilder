#include "../Headers/TexturePositionComparator.hpp"


TexturePositionComparator::TexturePositionComparator(
const SDL_Point& pos) : posOnScreen_(pos) {}

bool TexturePositionComparator::operator()(const Texture& texture) {
	const SDL_Point texturePosOnScreen = texture.get_pos_on_screen();
	return (texturePosOnScreen.x == posOnScreen_.x &&
	texturePosOnScreen.y == posOnScreen_.y);
}


bool TexturePositionComparator::operator()(Texture* texture) {
	const SDL_Point texturePosOnScreen = texture->get_pos_on_screen();
	return (texturePosOnScreen.x == posOnScreen_.x &&
	texturePosOnScreen.y == posOnScreen_.y);
}


