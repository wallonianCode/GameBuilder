#include "../Headers/SaveButton.hpp"


GameState* SaveButton::get_next_state() {
	return nullptr;
}


SaveButton::SaveButton() : MenuButton({DefaultSettings::x, 
Window::get_instance()->get_height()/12 + 3*DefaultSettings::yJump}, 
DefaultSettings::w, 
DefaultSettings::h, DefaultSettings::frameThickness, 
DefaultSettings::frameColor, DefaultSettings::fillColor,  
DefaultSettings::clickedFillColor, 
"Save", DefaultSettings::textColor) {}
