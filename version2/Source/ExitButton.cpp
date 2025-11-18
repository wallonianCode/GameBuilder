#include "../Headers/ExitButton.hpp"


GameState* ExitButton::get_next_state() {
	return new ExiterState();
}


ExitButton::ExitButton() : MenuButton({DefaultSettings::x, 
Window::get_instance()->get_height()/12 + 4*DefaultSettings::yJump}, 
DefaultSettings::w,
DefaultSettings::h, DefaultSettings::frameThickness,
DefaultSettings::frameColor, DefaultSettings::fillColor,
DefaultSettings::clickedFillColor,"Exit", 
DefaultSettings::textColor) {}
