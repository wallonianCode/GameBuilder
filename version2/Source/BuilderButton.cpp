#include "../Headers/BuilderButton.hpp"


GameState* BuilderButton::get_next_state() {
	BuilderState* builderState = new BuilderState();
	return builderState;
}


BuilderButton::BuilderButton() : MenuButton({DefaultSettings::x, 
Window::get_instance()->get_height()/12 + DefaultSettings::yJump}, 
DefaultSettings::w, DefaultSettings::h, DefaultSettings::frameThickness,
DefaultSettings::frameColor, DefaultSettings::fillColor, 
DefaultSettings::clickedFillColor,
"Build", DefaultSettings::textColor) {
/*
	std::cout << "BuilderButton::BuilderButton: " << "x: " <<
	DefaultSettings::x << " y: " << Window::get_instance()->get_height()/12 	+ DefaultSettings::yJump << "w: " << DefaultSettings::w << " h: " <<
	DefaultSettings::h << std::endl;
 */
}

