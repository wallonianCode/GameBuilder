#include "../Headers/Texture.hpp"

//--------------------- TEXTUREPOSCOMPARATOR -----------------------
bool TexturePosComparator::operator()(const Texture& texture) {
	SDL_Point pos = texture.get_pos_on_screen();
	return ((pos.x == posOnScreen_.x) && (pos.y == posOnScreen_.y));
}

bool TexturePosComparator::operator()(Texture* texture) {
	SDL_Point pos = texture->get_pos_on_screen();
	return ((pos.x == posOnScreen_.x) && (pos.y == posOnScreen_.y));
}

TexturePosComparator::TexturePosComparator(const SDL_Point& pos) : 
posOnScreen_(pos) {}


//---------------------- TEXTURE ----------------------------------

