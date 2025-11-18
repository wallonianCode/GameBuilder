#include "../Headers/PlayerButton.hpp"


GameState* PlayerButton::get_next_state() {
	return new PlayerState();
}


PlayerButton::PlayerButton() : 	MenuButton({DefaultSettings::x, 
Window::get_instance()->get_height()/12 + 2*DefaultSettings::yJump}, 
DefaultSettings::w, DefaultSettings::h, DefaultSettings::frameThickness, 
DefaultSettings::frameColor, DefaultSettings::fillColor,
DefaultSettings::clickedFillColor, "Play", DefaultSettings::textColor) {}
