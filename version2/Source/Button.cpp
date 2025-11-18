#include "../Headers/Button.hpp"


void Button::draw() {
	outRect_.draw();
	inRect_.draw();
}


GameState* Button::handle_event(SDL_Event& event) {
	GameState* retour = nullptr;
	switch(event.type) {
		case SDL_MOUSEMOTION:
			if (Collider::is_mouse_inside_frame(event.motion, outRect_)) {
				activate();
			}
			else {
				deactivate();
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (Collider::is_click_inside_frame(event.button, outRect_)) {
				retour = click();
			}
			break;
		default:
			break;
	}
	return retour;
}


void Button::activate() {
	inRect_.set_color(activeColor_);	
}


void Button::deactivate() {
	inRect_.set_color(inactiveColor_); 
}


GameState* Button::click() {	
	std::cout << "Button::click() : Calling the base method" <<
	std::endl;
	return nullptr;
}


Button::Button(const SDL_Point& posOnScreen,
const int& width, const int& height, 
const int& frameThickness, const SDL_Color& frameColor,
const SDL_Color& fillColor,
const SDL_Color& clickedFillColor) {
	outRect_ = Rectangle(posOnScreen, width, height, frameColor);
	inRect_ = Rectangle(
	{posOnScreen.x + frameThickness, posOnScreen.y + frameThickness},
	width - 2*frameThickness, height - 2*frameThickness, fillColor);
	inactiveColor_ = fillColor;
	activeColor_ = clickedFillColor;
}
