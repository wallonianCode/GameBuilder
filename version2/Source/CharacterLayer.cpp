#include "../Headers/CharacterLayer.hpp"


CharacterLayer::CharacterLayer(const int& width) : Layer(width) {
	init();
}


void CharacterLayer::init() {
  for (int i = 0; i < 12; i++) {
		Layer::add_texture(new Character(get_pos_on_grid(i), 
		static_cast<Character::Name::Type>(i)));
	}
}
